#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
int shared;
sem_t sem1, sem2;
void *func1()
{
    sem_wait(&sem1);
    printf("In function 1\n");
    sem_wait(&sem2);
    sem_post(&sem2);
    sem_post(&sem1);
}
void *func2()
{
    sem_wait(&sem2);
    printf("In function 2\n");
    sem_wait(&sem1);
    sem_post(&sem1);
    sem_post(&sem2);
}
void main()
{
    pthread_t tid1, tid2;
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);
    pthread_create(&tid1, NULL, func1, NULL);
    pthread_create(&tid2, NULL, func2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}