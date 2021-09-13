#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/*Escribe TEXT en el conector proporcionado por el descriptor de archivo SOCKET_FD.  */

void write_text (int socket_fd, const char* text)
{
  /* Escriba el número de bytes en la cadena, incluido
      incluido la terminacion null*/
  int length = strlen (text) + 1;
  write (socket_fd, &length, sizeof (length));
  /* Escribe la cadena  */
  write (socket_fd, text, length);
}

int main (int argc, char* const argv[])
{
  const char* const socket_name = argv[1];
  const char* const message = argv[2];
  int socket_fd;
  struct sockaddr_un name;

  /* Crea el socket.  */
  socket_fd = socket (PF_LOCAL, SOCK_STREAM, 0);
  /* Guarda el nombre del servidor en la dirección del socket.  */
  name.sun_family = AF_LOCAL;
  strcpy (name.sun_path, socket_name);
  /* Conecta el socket.  */
  connect (socket_fd, &name, SUN_LEN (&name));
  /* Escribe el texto en la línea de comando en el conector.  */
  write_text (socket_fd, message);
  close (socket_fd);
  return 0;
}
