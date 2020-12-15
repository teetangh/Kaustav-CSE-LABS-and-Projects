// Run Consumer code first then the Producer code
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[])
{
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int buffer;
    int bytes_read = 0;

    printf("Process %d opening FIFO O_RDONLY \n", getpid());

    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d \n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        res = read(pipe_fd, &buffer, sizeof(buffer));
        while (res > 0)
        {
            printf(" Hello %d \n", buffer);
            res = read(pipe_fd, &buffer, sizeof(buffer));
            bytes_read += res;
        }
        (void)close(pipe_fd);
    }
    else
        exit(EXIT_FAILURE);

    printf("Process %d finished %d bytes read \n", getpid(), bytes_read);
    exit(EXIT_FAILURE);
    return 0;
}
