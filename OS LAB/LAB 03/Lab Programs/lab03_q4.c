#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

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
        exit(0);
    }

    else
    {
        // wait(&status);
        printf(" \n I'm the parent ");
        printf(" \n Child returned %d\n ", status);
        execlp("/bin/ps", "ps", NULL);
        exit(0);
    }

    return 0;
}
