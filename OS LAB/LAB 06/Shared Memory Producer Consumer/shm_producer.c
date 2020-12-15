#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
// #include <fcntl.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "sh_com.h"

int main(int argc, char const *argv[])
{
    int running = 1;
    void *shared_memory = (void *)0;

    struct shared_use_st *shared_stuff;
    char buffer[BUFSIZ];

    int shmid;
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666, IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, "shmget failed \n");
        exit(EXIT_FAILURE);
    }

    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failed \n");
        exit(EXIT_FAILURE);
    }

    printf("Memory attached at %X\n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;

    while (running)
    {
        if (shared_stuff->written_by_you)
        {
            printf("You wrote: %s", shared_stuff->some_text);
            sleep(rand() % 4);
            shared_stuff->written_by_you = 0;
            if (strcmp(shared_stuff->some_text, "end", 3) == 0)
                running = 0;
        }
    }

    if (shmdt(shared_memory) == -1)
    {
        fprintf(stderr, "shmdt failed \n");
        exit(EXIT_FAILURE);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "shmctl(IPC_RMID) failed \n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
