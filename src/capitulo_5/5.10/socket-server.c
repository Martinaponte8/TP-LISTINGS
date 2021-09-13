#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/* Lea el texto del socket y lo impríme. Continua hasta que se cierre el socket. Devuelve un valor distinto de cero si el cliente envió un mensaje de "salir", cero en caso contrario.  */

int server (int client_socket)
{
  while (1) {
    int length;
    char* text;

    /* Primero, lea la longitud del mensaje de texto del socket. Si read devuelve cero, el cliente cerró la conexión. */
    if (read (client_socket, &length, sizeof (length)) == 0)
      return 0;
    /* Asigna un búfer para contener el texto.  */
    text = (char*) malloc (length);
    /* Lew el texto en sí e imprímalo. */
    read (client_socket, text, length);
    printf ("%s\n", text);
    /* Libera el buffer.  */
    free (text);
    /* Si el cliente envia el mensaje "salir", se termina.  */
    if (!strcmp (text, "quit"))
      return 1;
  }
}

int main (int argc, char* const argv[])
{
  const char* const socket_name = argv[1];
  int socket_fd;
  struct sockaddr_un name;
  int client_sent_quit_message;

  /* Crea el socket.  */
  socket_fd = socket (PF_LOCAL, SOCK_STREAM, 0);
  /* Indica que es un servidor. */
  name.sun_family = AF_LOCAL;
  strcpy (name.sun_path, socket_name);
  bind (socket_fd, &name, SUN_LEN (&name));
  /* Escucha las conexiones  */
  listen (socket_fd, 5);

  /* Acepta conexiones repetidamente, haciendo girar un server() para tratar con cada cliente. Continúe hasta que un cliente envíe un mensaje de "salir".  */
  do {
    struct sockaddr_un client_name;
    socklen_t client_name_len;
    int client_socket_fd;

    /* Acepta una conexion  */
    client_socket_fd = accept (socket_fd, &client_name, &client_name_len);
    /* Maneja la conexion  */
    client_sent_quit_message = server (client_socket_fd);
    /* Cierra nuestro extremo de la conexión*/
    close (client_socket_fd);
  }
  while (!client_sent_quit_message);

  /* Remueve el archivo socket  */
  close (socket_fd);
  unlink (socket_name);

  return 0;
}
