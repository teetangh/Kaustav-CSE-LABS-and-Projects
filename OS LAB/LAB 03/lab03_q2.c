#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *cmdargs[] = {"./lab03_q1", NULL};
    execv(cmdargs[0], cmdargs);

    printf("\n Wont be displayed \n");
    return 0;
}
