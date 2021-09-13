#include <stdio.h>
#include <unistd.h>

int main ()
{
  FILE* stream = popen ("sort", "w");
  fprintf (stream, "Esto es un test.\n");
  fprintf (stream, "Hola Mundo!!!.\n");
  fprintf (stream, "Mi perro tiene pulgas.\n");
  fprintf (stream, "Este programa es genial.\n");
  fprintf (stream, "Un pez,dos peces.\n");
  return pclose (stream);
}
