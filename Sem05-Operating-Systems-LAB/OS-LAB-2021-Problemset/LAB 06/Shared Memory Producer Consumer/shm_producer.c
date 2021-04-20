#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include "shm_common.h"

int main(int argc, char const *argv[])
{
    int running = 1;
    void *shared_memory = (void *)0;
    struct shared_use_st *shared_stuff;
    char buffer[BUFSIZ];

    int shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
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

    printf("Memory attached at %x \n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;
    // shared_stuff->written_by_you = true;

    while (running)
    {

        while (shared_stuff->written_by_you == true)
        {
            // sleep(1);
            printf("Waiting for the client \n");
        }

        fgets(buffer, BUFSIZ, stdin);
        strncpy(shared_stuff->some_text, buffer, TEXT_SIZE);
        shared_stuff->written_by_you = true;
        if (strncmp(buffer, "exit", 4) == 0)
            running = 0;
    }

    if (shmdt(shared_memory) == -1)
    {
        fprintf(stderr, "shmdt failed \n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);

    return 0;
}
