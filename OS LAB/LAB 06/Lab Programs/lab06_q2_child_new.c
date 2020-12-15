// Child
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
struct shared_use
{
    char c;
    char next_char;
};
int main()
{
    int running = 1;
    void *shared_memory = (void *)0;
    int shmid;
    struct shared_use *stuff;
    char buffer;
    shmid = shmget((key_t)1234, sizeof(struct shared_use), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, "shmget failure\n");
        exit(1);
    }
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failure\n");
        exit(1);
    }
    stuff = (struct shared_use *)shared_memory;
    printf("Current character: %c\n", stuff->c);
    stuff->c++;
    if (shmdt(shared_memory) == -1)
    {
        fprintf(stderr, "shmdt failure\n");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "shmctl(IP_RMID) failure\n");
        exit(1);
    }
}