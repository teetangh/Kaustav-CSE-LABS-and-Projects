#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed \n");
        exit(-1);
    }
    else if (pid == 0)
        execlp("/bin/ls", "ls", NULL);
    else
    {
        wait(NULL);
        printf("Child Complete \n");
        exit(0);
    }

    return 0;
}
