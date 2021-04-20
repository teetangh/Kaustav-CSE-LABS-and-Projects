#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <unistd.h>

struct lab06_q2_structure
{
    long int written_by_you;
    char sharedCharacter;
};

int main(int argc, char const *argv[])
{

    void *shared_memory = (void *)0;
    struct lab06_q2_structure *shared_stuff;

    int shmid = shmget(shmid, sizeof(shared_stuff), 0666 | IPC_CREAT);
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

    // printf("Memory attached at %x ", (int)shared_memory);
    shared_stuff = (struct lab06_q2_structure *)shared_memory;

    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "fork failed \n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // sleep(1);
        sleep(3);
        printf("********* child process *********\n");
        shared_stuff->sharedCharacter += 1;
    }
    else
    {
        printf("********* parent process *********\n");
        printf("Enter a character \n");
        // char scannedChar = fgetc(stdin);
        // char scannedChar = getchar();

        // shared_stuff->sharedCharacter = scannedChar;
        scanf(" %c", &(shared_stuff->sharedCharacter));
        wait(NULL);

        printf("After incrementing %c \n", shared_stuff->sharedCharacter);
    }

    return 0;
}
