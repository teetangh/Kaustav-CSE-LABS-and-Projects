#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int res = mkfifo("/tmp/myfifo", 0777);
    if (res == 0)
        printf("FIFO CREATED \n");
    else
        printf("FIFO CREATION FAILED \n");

    exit(EXIT_SUCCESS);
    return 0;
}