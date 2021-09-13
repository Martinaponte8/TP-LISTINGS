#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

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

/* A mutex protecting job_queue.  */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Un semáforo contando el número de trabajos en la cola.  */
sem_t job_queue_count;

/* Realiza una inicialización única de la cola de trabajos.  */

void initialize_job_queue ()
{
  /* La cola está inicialmente vacía.  */
  job_queue = NULL;
  /* Inicializa el semáforo que cuenta los trabajos en la cola. Su
     valor inicial debe ser CERO.  */
  sem_init (&job_queue_count, 0, 0);
}

/* Procesar trabajos encolados hasta que la cola quede vacía.  */

void* thread_function (void* arg)
{
  while (1) {
    struct job* next_job;

    /* Esperar en el semáforo de la cola del trabajo. Si su valor es positivo,
       indicando que la cola no está vacía, decrementar el contador
       en UNO.  Si la cola está vacía, bloquear hasta que un nuevo trabajo quede encolado.  */
    sem_wait (&job_queue_count);

    /* Bloquea el mutex en la cola de trabajo..  */
    pthread_mutex_lock (&job_queue_mutex);
    /* Gracias al semáforo, sabemos que la cola no está vacía.  Obtiene
       el próximo trabajo disponible.  */
    next_job = job_queue;
    /* Remueve este trabajo de la lista.  */
    job_queue = job_queue->next;
    /* Desbloquea el mutex en la cola de trabajo, como el trabajo sobre la cola
       ya está hecho por ahora.  */
    pthread_mutex_unlock (&job_queue_mutex);

    /* Lleva el trabajo.  */
    process_job (next_job);
    /* Limpia.  */
    free (next_job);
  }
  return NULL;
}

/* Agrega un nuevo trabajo al frente de la cola.  */

void enqueue_job (int k)
{
  struct job* new_job;

  /* Allocate a new job object.  */
  new_job = (struct job*) malloc (sizeof (struct job));
  /* Set the other fields of the job struct here...  */

  new_job->k=k;

  /* Lock the mutex on the job queue before accessing it.  */
  pthread_mutex_lock (&job_queue_mutex);
  /* Place the new job at the head of the queue.  */
  new_job->next = job_queue;
  job_queue = new_job;

  /* Post to the semaphore to indicate another job is available.  If
     threads are blocked, waiting on the semaphore, one will become
     unblocked so it can process the job.  */
  sem_post (&job_queue_count);

  /* Unlock the job queue mutex.  */
  pthread_mutex_unlock (&job_queue_mutex);
}


int main() {

  pthread_t threads[2];
  int i;

  // pthread_t thread_id;

  initialize_job_queue();

  enqueue_job(1);
  enqueue_job(2);
  enqueue_job(3);
  enqueue_job(4);
  enqueue_job(5);
  enqueue_job(6);
  enqueue_job(7);
  enqueue_job(8);
  enqueue_job(9);
  enqueue_job(10);

  for (i = 0; i < 10; ++i)
    pthread_create(&(threads[i]), NULL, &thread_function, NULL);
  for (i = 0; i < 10; ++i)
    pthread_join(threads[i], NULL);

  return 0;
}