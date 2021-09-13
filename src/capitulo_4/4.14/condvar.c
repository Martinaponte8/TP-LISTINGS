#include <pthread.h>
#include <stdio.h>

void do_work () {
  printf("haciendo trabajo\n");
}

int thread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;

void initialize_flag ()
{
  /* Inicializa el mutex y la variable de condición.  */
  pthread_mutex_init (&thread_flag_mutex, NULL);
  pthread_cond_init (&thread_flag_cv, NULL);
  /* Inicializa el valor de la bandera.  */
  thread_flag = 0;
}

/* Llama a do_work repetidamente mientras el hilo está on; bloquea si
   la bandera esta limpia.  */

void* thread_function (void* thread_arg)
{
  /* Loop infinitamente.  */
  while (1) {
    /* Bloquea el mutex antes de acceder al valor de la bandera.  */
    pthread_mutex_lock (&thread_flag_mutex);
    while (!thread_flag) 
      /* La bandera está limpia.  Esperando por la señal de la condición
     de la variable, indicando que el valor ha cambiado.  Cuando la señal llegue 
     y este hilo se desbloquee, loopear y checkear la bandera de vuelta. */
      pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex);
    /* Cuando estamos aquí, sabemos que la bandera debe ser seteada.  Desbloquea
       el mutex.  */
    pthread_mutex_unlock (&thread_flag_mutex);
    /* Hace algun trabajo.  */
    do_work ();
  }
  return NULL;
}

/* Setea el valor de la bandera del hilo a FLAG_VALUE.  */

void set_thread_flag (int flag_value)
{
  /* Bloquea el mutex antes de acceder al valor de la bandera.  */
  pthread_mutex_lock (&thread_flag_mutex);
  /* Setear el valor de la bandera, y la señal en caso de que thread_function esté
     bloqueado, esperando ser seteado por la bandera. De todos modos,
     thread_function no puede chekear la bandera hasta que el mutex esté desbloqueado. */
  thread_flag = flag_value;
  pthread_cond_signal (&thread_flag_cv);
  /* Desbloquea el mutex.  */
  pthread_mutex_unlock (&thread_flag_mutex);
}

int main() {

  pthread_t thread_id;
  initialize_flag();

  set_thread_flag(2);

  pthread_create(&thread_id, NULL, &thread_function, NULL);
  pthread_join(thread_id, NULL);

  return 0;
}