#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct job {
  /* campo link al siguiente trabajo para la lista enlazada.  */
  struct job* next; 

  /* otros campos extra que podría usar el trabajo... */
  int k;
};

/* Una lista enlazada de trabajos pendientes.  */
struct job* job_queue;

void process_job (struct job* parameters) {
  
  struct job* p = (struct job*) parameters; 
  
  printf("%d\n", p->k);
  return;
}

/* Un mutex protegiendo job_queue.  */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Procesar trabajos encolados hasta que la lista quede vacía.  */

void* thread_function (void* arg)
{
  while (1) {
    struct job* next_job;

    /* Bloquea el mutex en la cola de trabajo.  */
    pthread_mutex_lock (&job_queue_mutex);
    /* Ahora es seguro checkear si la cola está vacía.  */
    if (job_queue == NULL)
      next_job = NULL;
    else {
      /* Agarra el próximo trabajo disponible.  */
      next_job = job_queue;
      /* Remueve este trabajo de la lista.  */
      job_queue = job_queue->next;
    }
    /* Desbloquea el mutex en la cola de trabajo, como el trabajo sobre la cola
       ya está hecho por ahora.  */
    pthread_mutex_unlock (&job_queue_mutex);

    /* Estaba la cola vacía? Si es así, termina el hilo.  */
    if (next_job == NULL)
      break;

    /* Lleva el trabajo.  */
    process_job (next_job);
    /* Limpia.  */
    free (next_job);
  }
  return NULL;
}


int main() {

  pthread_t threads[2];
  int i;

  struct job* first = NULL;
  struct job* second = NULL;
  struct job* third = NULL;

  job_queue = (struct job*)malloc(sizeof(struct job));
  first = (struct job*)malloc(sizeof(struct job));
  second = (struct job*)malloc(sizeof(struct job));
  third = (struct job*)malloc(sizeof(struct job));

  job_queue->k=0;
  job_queue->next = first;

  first->k = 1;
  first->next = second;
  
  second->k = 2;
  second->next = third;

  third->k=3;
  third->next = NULL;

  // pthread_t thread_id;
  for (i = 0; i < 2; ++i)
    pthread_create(&(threads[i]), NULL, &thread_function, NULL);
  for (i = 0; i < 2; ++i)
    pthread_join(threads[i], NULL);

  return 0;
}