#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *cmdargs[] = {"grep", "-I", "-n", "SUMIT", "/etc/passed", NULL};
    execv("/bin/grep", cmdargs);
    printf("execv error \n");
    return 0;
}
