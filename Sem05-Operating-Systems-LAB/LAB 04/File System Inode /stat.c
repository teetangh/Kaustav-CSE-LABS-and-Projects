#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct stat statbuf;
    int ret;
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <file> \n", argv[0]);
        return 1;
    }

    ret = stat(argv[1], &statbuf);
    if (ret)
    {
        perror("stat");
        return 1;
    }

    printf("%s is %ld bytes\n", argv[1], statbuf.st_size);

    return 0;
}
