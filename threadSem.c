/* just playing with threads and semaphores - wrote it originally without the semaphores to watch the interleaving / added the semaphores to see the difference */

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int runningTotal;
sem_t sem;

void *thread_function(void *arg)
{
  for (int i = 0; i < 100; i++)  
    {
      sem_wait(&sem);
      int j = runningTotal;
      usleep(100);
      j = j + 1;
      fprintf(stdout, "thread_function() -> Current total = %d\n", runningTotal);
      runningTotal = j;
      sem_post(&sem);
    }
  return NULL;
}

int
main(void)
{
  pthread_t mythread;
  sem_init(&sem, 0, 1);
  if (pthread_create(&mythread, NULL, thread_function, NULL))
  {
    printf("Error creating thread.");
    exit(1);
  }

  for (int i = 0; i < 100; i++)
    { 
      sem_wait(&sem);
      runningTotal = runningTotal + 1;      
      fprintf(stdout, "Main() -> Current total: %d\n", runningTotal);
      sem_post(&sem);
    }

  pthread_join(mythread, NULL);
  sem_destroy(&sem);
  exit(0);
}
