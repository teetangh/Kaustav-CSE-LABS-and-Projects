#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define PIPE_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[])
{
    int n, pipe_fd, res;
    char buffer[BUFFER_SIZE];
    int open_mode = O_RDONLY;
    int curr_number;

    pipe_fd = open(PIPE_NAME, open_mode);
    if (pipe_fd != -1)
    {
        res = read(pipe_fd, &curr_number, sizeof(buffer));
        while (res > 0)
        {
            printf("The current number read by the consumer is %d \n", curr_number);
            res = read(pipe_fd, &curr_number, sizeof(buffer));
        }
    }
    (void)close(pipe_fd);
    exit(EXIT_SUCCESS);
}