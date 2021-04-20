#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *cmdargs[] = {"grep", "-I", "-n", "exec", "/home/kaustav/Desktop/KaustavLABS3/OS LAB/LAB 03/More System Calls/exec.txt", NULL};
    execv("/bin/grep", cmdargs);
    printf("execv error \n");
    return 0;
}
