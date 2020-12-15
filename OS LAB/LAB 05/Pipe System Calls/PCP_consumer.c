#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myfifo"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[])
{
    int pipe_fd;
    int result;
    int open_mode = O_RDONLY;

    int bytes_read = 0;
    char buffer[BUFFER_SIZE + 1];

    memset(buffer, 0, sizeof(buffer));
    printf("Process %d opening pipe in O_RDONLY mode\n ", getpid());
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    printf("Process pid %d result %d \n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        do
        {
            result = read(pipe_fd, buffer, BUFFER_SIZE);
            bytes_read += result;
        } while (result > 0);
        (void)close(pipe_fd);
    }

    printf("Process %d Finished %d bytes read \n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);

    return 0;
}
