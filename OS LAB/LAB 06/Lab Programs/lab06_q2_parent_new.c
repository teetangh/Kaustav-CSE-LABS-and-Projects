// Parent
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
    srand((unsigned int)getpid());
    shmid = shmget((key_t)1234, sizeof(struct shared_use), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        fprintf(stderr, "shmget failure!!\n");
        exit(EXIT_FAILURE);
    }
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        fprintf(stderr, "shmat failure\n");
        exit(EXIT_FAILURE);
    }
    stuff = (struct shared_use *)shared_memory;
    char ch;
    printf("Enter a character:\n");
    scanf("%c", &ch);
    stuff->c = ch;
    printf("current char: %c\n", stuff->c);
    printf("Waiting for child process to change\n");
    sleep(4);
    printf("Current character: %c\n", stuff->c);
    if (shmdt(shared_memory) == -1)
    {
        fprintf(stderr, "shmdt failure\n");
        exit(EXIT_FAILURE);
    }
}