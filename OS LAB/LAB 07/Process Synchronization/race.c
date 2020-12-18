// gcc -g race.c -lpthread &&  valgrind --tool=helgrind ./a.out 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int counter = 0;
void *func(void *params) { counter++; }

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, 0, func, 0);
    pthread_create(&thread2, 0, func, 0);

    pthread_join(thread1, 0);
    pthread_join(thread2, 0);

    return 0;
}
