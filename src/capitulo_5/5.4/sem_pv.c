#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

//struct sembuf{
//	unsigned short sem_num;  /* semaphore number */
//	short          sem_op;   /* semaphore operation */
//	short          sem_flg;  /* operation flags */

//}

int main(){
	struct sembuf *s;
	int semid = 2;
	size_t t = (long unsigned int)s;
	semop(semid,s,t);
return 0;
}


/* Wait on a binary semaphore. Block until the semaphore value is positive,
then
decrement it by 1. */
int binary_semaphore_wait (int semid)
{
	struct sembuf operations[1];
	/* Use the first (and only) semaphore. */
	operations[0].sem_num = 0;
	/* Decrement by 1. */
	operations[0].sem_op = -1;
	/* Permit undo'ing. */
	operations[0].sem_flg = SEM_UNDO;
	return semop (semid, operations, 1);
}
/* Post to a binary semaphore: increment its value by 1.
This returns immediately. */
int binary_semaphore_post (int semid)
{
	struct sembuf operations[1];
	/* Use the first (and only) semaphore. */
	operations[0].sem_num = 0;
	/* Increment by 1. */
	operations[0].sem_op = 1;
	/* Permit undo'ing. */
	operations[0].sem_flg = SEM_UNDO;
	return semop (semid, operations, 1);
}
