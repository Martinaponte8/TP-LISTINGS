##Makefile TP-LISTINGS

CC=gcc
CFLAGS= -g -Wall
EJS = listing-1.1 listing-2.1 listing-2.2 listing-2.3 listing-2.4 listing-2.5 listing-2.6 listing-2.8 listing-3.1 listing-3.2 listing-3.3 listing-3.4 listing-3.5 listing-3.6 listing-3.7 listing-4.1 listing-4.2 listing-4.3 listing-4.4 listing-4.5 listing-4.6 listing-4.7 listing-4.8 listing-4.9 listing-4.10 listing-4.11 listing-4.12 listing-4.13 listing-4.14 listing-4.15 listing-5.1 listing-5.2 listing-5.3 listing-5.4 listing-5.5 listing-5.6 listing-5.7 listing-5.8 listing-5.9 listing-5.10 listing-5.11 listing-5.12 listing-2.9
##El listing-2.9 se compila ultimo, debe descargar la libreria libtiff, caso contrario retorna error


.PHONY: all
all:	$(EJS) 


## reciprocal.cpp - C++ source file
listing-1.1: ./src/capitulo_1/main.o 
	$(CC) $(CFLAGS) -o reciprocal ./src/capitulo_1/main.o ./src/capitulo_1/reciprocal.cpp 
	mv reciprocal ./bin/capitulo_1/

##  getopt_long - getopt_long function
listing-2.1: ./src/capitulo_2/2.1/arglist.o
	$(CC) $(CFLAGS) -o arglist ./src/capitulo_2/2.1/arglist.o
	mv arglist ./bin/capitulo_2/2.1/ 

##  getopt_long - getopt_long function
listing-2.2: ./src/capitulo_2/2.2/getopt_long.o
	$(CC) $(CFLAGS) -o getopt_long ./src/capitulo_2/2.2/getopt_long.o
	mv getopt_long ./bin/capitulo_2/2.2/ 


##  print_env - printing execution environment
listing-2.3: ./src/capitulo_2/2.3/print_env.o
	$(CC) $(CFLAGS) -o print_env ./src/capitulo_2/2.3/print_env.o
	mv print_env ./bin/capitulo_2/2.3/ 


##  client - network client program
listing-2.4: ./src/capitulo_2/2.4/client.o
	$(CC) $(CFLAGS) -o client ./src/capitulo_2/2.4/client.o
	mv client ./bin/capitulo_2/2.4/ 


##  temp_file - mkstemp function
listing-2.5: ./src/capitulo_2/2.5/temp_file.o
	$(CC) $(CFLAGS) -o temp_file ./src/capitulo_2/2.5/temp_file.o
	mv temp_file ./bin/capitulo_2/2.5/ 


##  readfile - resource allocation during error checking
listing-2.6: ./src/capitulo_2/2.6/readfile.o
	$(CC) $(CFLAGS) -o readfile ./src/capitulo_2/2.6/readfile.o
	mv readfile ./bin/capitulo_2/2.6/ 

##  app - program with library functions
listing-2.8: ./src/capitulo_2/2.8/app.o
	$(CC) $(CFLAGS) -o app ./src/capitulo_2/2.8/app.o ./src/capitulo_2/2.7/test.c
	mv app ./bin/capitulo_2/2.8/ 


##  print-pid - printing process IDs
listing-3.1: ./src/capitulo_3/3.1/print-pid.o
	$(CC) $(CFLAGS) -o print-pid ./src/capitulo_3/3.1/print-pid.o
	mv print-pid ./bin/capitulo_3/3.1/


##  system - system function
listing-3.2: ./src/capitulo_3/3.2/system.o
	$(CC) $(CFLAGS) -o system ./src/capitulo_3/3.2/system.o
	mv system ./bin/capitulo_3/3.2/


##  fork - fork function
listing-3.3: ./src/capitulo_3/3.3/fork.o
	$(CC) $(CFLAGS) -o fork ./src/capitulo_3/3.3/fork.o
	mv fork ./bin/capitulo_3/3.3/


##  fork-exec - fork and exec functions
listing-3.4: ./src/capitulo_3/3.4/fork-exec.o
	$(CC) $(CFLAGS) -o fork-exec ./src/capitulo_3/3.4/fork-exec.o
	mv fork-exec ./bin/capitulo_3/3.4/


##  sigusr1 - signal handlers
listing-3.5: ./src/capitulo_3/3.5/sigusr1.o
	$(CC) $(CFLAGS) -o sigusr1 ./src/capitulo_3/3.5/sigusr1.o
	mv sigusr1 ./bin/capitulo_3/3.5/


##  zombie - zombie processes
listing-3.6: ./src/capitulo_3/3.6/zombie.o
	$(CC) $(CFLAGS) -o zombie ./src/capitulo_3/3.6/zombie.o
	mv zombie ./bin/capitulo_3/3.6/


##  sigchld - cleaning up child processes
listing-3.7: ./src/capitulo_3/3.7/sigchld.o
	$(CC) $(CFLAGS) -o sigchld ./src/capitulo_3/3.7/sigchld.o
	mv sigchld ./bin/capitulo_3/3.7/


##  thread-create - creating one threads 
listing-4.1: ./src/capitulo_4/4.1/thread-create.o 
	$(CC)  -pthread  $(CFLAGS) -o thread-create ./src/capitulo_4/4.1/thread-create.o 
	mv thread-create ./bin/capitulo_4/4.1/

##  thread-create2 - creating two threads 
listing-4.2: ./src/capitulo_4/4.2/thread-create2.o 
	$(CC) -pthread $(CFLAGS) -o thread-create2 ./src/capitulo_4/4.2/thread-create2.o 
	mv thread-create2 ./bin/capitulo_4/4.2/


##  thread-create2 - revised main fuction 
listing-4.3: ./src/capitulo_4/4.3/thread-create2.o 
	$(CC) -pthread $(CFLAGS) -o thread-create2 ./src/capitulo_4/4.3/thread-create2.o 
	mv thread-create2 ./bin/capitulo_4/4.3/


##  primes - prime number computation in a thread 
listing-4.4: ./src/capitulo_4/4.4/primes.o 
	$(CC) -pthread $(CFLAGS) -o primes ./src/capitulo_4/4.4/primes.o 
	mv primes ./bin/capitulo_4/4.4/


##  detached - creating detached threads 
listing-4.5: ./src/capitulo_4/4.5/detached.o 
	$(CC) -pthread $(CFLAGS) -o detached ./src/capitulo_4/4.5/detached.o 
	mv detached ./bin/capitulo_4/4.5/


##  critical-section - critical sections 
listing-4.6: ./src/capitulo_4/4.6/critical-section.o 
	$(CC) -pthread $(CFLAGS) -o critical-section ./src/capitulo_4/4.6/critical-section.o 
	mv critical-section ./bin/capitulo_4/4.6/


##  tsd - thread-specific data 
listing-4.7: ./src/capitulo_4/4.7/tsd.o 
	$(CC) -pthread $(CFLAGS) -o tsd ./src/capitulo_4/4.7/tsd.o 
	mv tsd ./bin/capitulo_4/4.7/


##  cleanup - cleanun handlers 
listing-4.8: ./src/capitulo_4/4.8/cleanup.o 
	$(CC) -pthread $(CFLAGS) -o cleanup ./src/capitulo_4/4.8/cleanup.o 
	mv cleanup ./bin/capitulo_4/4.8/


##  cxx-exit - C++ thread cleanup 
listing-4.9: ./src/capitulo_4/4.9/cxx-exit.o 
	g++ -pthread $(CFLAGS) -o cxx-exit ./src/capitulo_4/4.9/cxx-exit.o 
	mv cxx-exit ./bin/capitulo_4/4.9/


##  job-queue1 - thread race conditions 
listing-4.10: ./src/capitulo_4/4.10/job-queue1.o 
	$(CC) -pthread $(CFLAGS) -o job-queue1 ./src/capitulo_4/4.10/job-queue1.o 
	mv job-queue1 ./bin/capitulo_4/4.10/


##  job-queue2 - mutexes 
listing-4.11: ./src/capitulo_4/4.11/job-queue2.o 
	$(CC) -pthread $(CFLAGS) -o job-queue2 ./src/capitulo_4/4.11/job-queue2.o 
	mv job-queue2 ./bin/capitulo_4/4.11/


##  job-queue3 - semaphores 
listing-4.12: ./src/capitulo_4/4.12/job-queue3.o 
	$(CC) -pthread $(CFLAGS) -o job-queue3 ./src/capitulo_4/4.12/job-queue3.o 
	mv job-queue3 ./bin/capitulo_4/4.12/

##   spin-condvar - condition variables 
listing-4.13: ./src/capitulo_4/4.13/spin-condvar.o 
	$(CC) -pthread $(CFLAGS) -o spin-condvar ./src/capitulo_4/4.13/spin-condvar.o 
	mv spin-condvar ./bin/capitulo_4/4.13/


##  condvar - printing thread process IDs 
listing-4.14: ./src/capitulo_4/4.14/condvar.o 
	$(CC) -pthread $(CFLAGS) -o condvar ./src/capitulo_4/4.14/condvar.o 
	mv condvar ./bin/capitulo_4/4.14/


##  thread-pid - Print Process ID for Thread 
listing-4.15: ./src/capitulo_4/4.15/thread-pid.o 
	$(CC) -pthread $(CFLAGS) -o thread-pid ./src/capitulo_4/4.15/thread-pid.o 
	mv thread-pid ./bin/capitulo_4/4.15/
	
	
##  shm - shared memory 
listing-5.1: ./src/capitulo_5/5.1/shm.o 
	$(CC) $(CFLAGS) -o shm ./src/capitulo_5/5.1/shm.o 
	mv shm ./bin/capitulo_5/5.1/


##  sem_all_deall - semaphore allocation and deallocation 
listing-5.2: ./src/capitulo_5/5.2/sem_all_deall.o 
	$(CC) $(CFLAGS) -o sem_all_deall ./src/capitulo_5/5.2/sem_all_deall.o 
	mv sem_all_deall ./bin/capitulo_5/5.2/


##  sem_init - semaphore initialization 
listing-5.3: ./src/capitulo_5/5.3/sem_init.o 
	$(CC) $(CFLAGS) -o sem_init ./src/capitulo_5/5.3/sem_init.o 
	mv sem_init ./bin/capitulo_5/5.3/


##  sem_pv - semaphore wait and post operations 
listing-5.4: ./src/capitulo_5/5.4/sem_pv.o 
	$(CC) $(CFLAGS) -o sem_pv ./src/capitulo_5/5.4/sem_pv.o 
	mv sem_pv ./bin/capitulo_5/5.4/


##  mmap-write - mapped memory 
listing-5.5: ./src/capitulo_5/5.5/mmap-write.o 
	$(CC) $(CFLAGS) -o mmap-write ./src/capitulo_5/5.5/mmap-write.o 
	mv mmap-write ./bin/capitulo_5/5.5/


##  mmap-read - mapped memory 
listing-5.6: ./src/capitulo_5/5.6/mmap-read.o 
	$(CC) $(CFLAGS) -o mmap-read ./src/capitulo_5/5.6/mmap-read.o 
	mv mmap-read ./bin/capitulo_5/5.6/


##  pipe - parent-child proces communication 
listing-5.7: ./src/capitulo_5/5.7/pipe.o 
	$(CC) $(CFLAGS) -o pipe ./src/capitulo_5/5.7/pipe.o 
	mv pipe ./bin/capitulo_5/5.7/


##  dup2 - output redirection 
listing-5.8: ./src/capitulo_5/5.8/dup2.o 
	$(CC) $(CFLAGS) -o dup2 ./src/capitulo_5/5.8/dup2.o 
	mv dup2 ./bin/capitulo_5/5.8/


##  popen - popen command 
listing-5.9: ./src/capitulo_5/5.9/popen.o 
	$(CC) $(CFLAGS) -o popen ./src/capitulo_5/5.9/popen.o 
	mv popen ./bin/capitulo_5/5.9/


##  socket-server - local sockets 
listing-5.10: ./src/capitulo_5/5.10/socket-server.o 
	$(CC) $(CFLAGS) -o socket-server ./src/capitulo_5/5.10/socket-server.o 
	mv socket-server ./bin/capitulo_5/5.10/


##  socket-client - local sockets 
listing-5.11: ./src/capitulo_5/5.11/socket-client.o 
	$(CC) $(CFLAGS) -o socket-client ./src/capitulo_5/5.11/socket-client.o 
	mv socket-client ./bin/capitulo_5/5.11/


##  socket-inet - internet-domain sockets 
listing-5.12: ./src/capitulo_5/5.12/socket-inet.o 
	$(CC) $(CFLAGS) -o socket-inet ./src/capitulo_5/5.12/socket-inet.o 
	mv socket-inet ./bin/capitulo_5/5.12/
	
##compila ultimo porque se debe tener la libreria libtiff
##  tifftest - libtiff library 
listing-2.9: ./src/capitulo_2/2.9/tifftest.o
	$(CC) -lm -ltiff $(CFLAGS) -o tifftest ./src/capitulo_2/2.9/tifftest.o 
	mv tifftest ./bin/capitulo_2/2.9/ 


##ELIMINA TODAS LAS COMPILACIONES EXISTENTES
clean: 
	find . -name "*.o" -type f -delete
	 
#ELIMINA TODOS LOS EJECUTABLES EXISTENTES
clear:
	find ./bin -name "*" -type f -delete

