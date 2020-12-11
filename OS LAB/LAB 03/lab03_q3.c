#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

void display_info()
{
    //getpid() - will return process id of calling function
    pid_t process_id = getpid();
    //getppid() - will return process id of parent function
    pid_t p_process_id = getppid();

    //printing the process ids
    printf("The process id: %d\n", process_id);
    printf("The process id of parent function: %d\n", p_process_id);
}

int main(int argc, char const *argv[])
{
    int status;
    pid_t pid;
    pid = fork();

    if (pid == -1)
        printf("\n ERROR child not created \n");

    else if (pid == 0)
    {
        printf(" I am the child ! \n");
        display_info();
        exit(0);
    }

    else
    {
        wait(&status);
        printf(" \n I'm the parent ");
        printf(" \n Child returned %d\n ", status);

        display_info();
    }

    return 0;
}
