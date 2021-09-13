#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
  int fds[2];
  pid_t pid;

  /* Crea un pipe. Los descriptores de archivo para los dos extremos del pipe se colocan en fds.  */
  pipe (fds);
  /* Bifurca un proceso hijo. */
  pid = fork ();
  if (pid == (pid_t) 0) {
    /* Este es el proceso hijo. Cierra nuestra copia del final de escritura del descriptor de archivo.  */
    close (fds[1]);
    /* Conecta el extremo de lectura del pipe a la entrada estándar.  */
    dup2 (fds[0], STDIN_FILENO);
    /* Reemplace el proceso hijo con el programa "sort".  */
    execlp ("sort", "sort", 0);
  }
  else {
    /* Este es el proceso padre  */
    FILE* stream;
    /* Cierra nuestra copia del final de lectura del descriptor de archivo.  */
    close (fds[0]);
    /* Convierta el descriptor del archivo de escritura en un objeto FILE y escriba en él.  */
    stream = fdopen (fds[1], "w");
    fprintf (stream, "Esto es un test.\n");
    fprintf (stream, "Hello, world.\n");
    fprintf (stream, "My dog has fleas.\n");
    fprintf (stream, "This program is great.\n");
    fprintf (stream, "One fish, two fish.\n");
    fflush (stream);
    close (fds[1]);
    /*Espera a que finalice el proceso secundario.  */
    waitpid (pid, NULL, 0);
  }

  return 0;
}
