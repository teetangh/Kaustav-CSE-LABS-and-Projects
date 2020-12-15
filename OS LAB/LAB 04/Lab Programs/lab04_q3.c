#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <file> \n", argv[0]);
        return 1;
    }
    char sln[] = "test.link";
    puts("Before link()");
    system("readlink -f test.*");

    // Hard link
    if (link(argv[1], sln) != 0)
    {
        perror("link error");
        unlink(argv[1]);
    }
    else
    {
        puts("After link()");
        system("readlink -f test.*");

        unlink(argv[1]);
        puts("after first unlink()");
        system("readlink -f test.*");

        unlink(sln);
    }

    return 0;
}
