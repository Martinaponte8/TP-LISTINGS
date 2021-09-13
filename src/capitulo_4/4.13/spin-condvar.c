#include <pthread.h>
#include <stdio.h>

void do_work (){
  printf("hello\n");
};

int thread_flag;
pthread_mutex_t thread_flag_mutex;

void initialize_flag ()
{
  pthread_mutex_init (&thread_flag_mutex, NULL);
  thread_flag = 0;
}

/* Llama a do_work repetidamente mientras el hilo de la bandera este on; de otro modo hace un giro.  */

void* thread_function (void* thread_arg)
{
  while (1) {
    int flag_is_set;

    /* Protege la bandera con un mutex lock.  */
    pthread_mutex_lock (&thread_flag_mutex);
    flag_is_set = thread_flag;
    pthread_mutex_unlock (&thread_flag_mutex);

    if (flag_is_set)
      do_work ();
    /* Sino no hacer nada.  Solo volver a hacer el loop.  */
  }
  return NULL;
}

/* Setea el valor de la bandera del hilo a FLAG_VALUE.  */

void set_thread_flag (int flag_value)
{
  /* Protege la bandera con un mutex lock.  */
  pthread_mutex_lock (&thread_flag_mutex);
  thread_flag = flag_value;
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