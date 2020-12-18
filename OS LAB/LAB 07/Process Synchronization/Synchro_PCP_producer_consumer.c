#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer[5], f, r;
sem_t mutex, full, empty;

void *produce(void *arg)
{
    int i;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        printf("produced item is %d \n", i);
        buffer[(++r) % 5] = i;
        sleep(1);

        sem_post(&mutex);
        sem_post(&full);
        printf("full %u\n", full);
    }
}

void *consume(void *arg)
{
    int item, i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&full);
        printf("full %u\n", full);

        sem_wait(&mutex);
        item = buffer[(++f) % 5];

        printf("consumed item is %d \n", item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 1);

    pthread_create(&tid1, NULL, produce, NULL);
    pthread_create(&tid2, NULL, consume, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
