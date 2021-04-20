#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n;
    int fd[2];
    char buffer[1025];

    char *data = "This is sample data";
    pipe(fd);

    write(fd[1], data, strlen(data));
    if ((n = read(fd[0], buffer, 1024)) >= 0)
    {
        buffer[n] = '\0';
        printf("Read %d bytes from the pipe: %s \n", n, buffer);
    }
    else
    {
        perror("read");
    }

    exit(0);
}
