#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Escribe COUNT copias de MESSAGE para STREAM, haciendo una pausa por un segundo
    entre cada uno.  */

void writer (const char* message, int count, FILE* stream)
{
  for (; count > 0; --count) {
    /* Escribe el mensaje en la transmisión y envíalo de inmediato.  */
    fprintf (stream, "%s\n", message);
    fflush (stream);
    /* Posponer un rato.  */
    sleep (1);
  }
}

/* Lee cadenas aleatorias de la transmisión el mayor tiempo posible. */

void reader (FILE* stream)
{
  char buffer[1024];
  /* Lee hasta que lleguemos al final de la transmisión. fgets lee hasta una nueva línea o el final del archivo.  */
  while (!feof (stream) 
	 && !ferror (stream) 
	 && fgets (buffer, sizeof (buffer), stream) != NULL) 
    fputs (buffer, stdout);
}

int main ()
{
  int fds[2];
  pid_t pid;

  /* Crea un pipe. Los descriptores de archivo para los dos extremos de la tubería se colocan en fds.  */
  pipe (fds);
  /* Bifurca un proceso hijo.  */
  pid = fork ();
  if (pid == (pid_t) 0) {
    FILE* stream;
    /* Este es el proceso hijo. Cierre nuestra copia del final de escritura del descriptor de archivo.  */
    close (fds[1]);
    /* Convierte el descriptor de archivo leído en un objeto FILE y lea de él. */
    stream = fdopen (fds[0], "r");
    reader (stream);
    close (fds[0]);
  }
  else {
    /* Este es el proceso padre  */
    FILE* stream;
    /* Cierre nuestra copia del final de lectura del descriptor de archivo.  */
    close (fds[0]);
    /* Convierte el descriptor del archivo de escritura en un objeto FILE y escriba en él. */
    stream = fdopen (fds[1], "w");
    writer ("Hola world!!!.", 7, stream);
    close (fds[1]);
  }

  return 0;
}
