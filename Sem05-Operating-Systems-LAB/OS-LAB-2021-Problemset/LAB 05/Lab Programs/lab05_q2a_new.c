#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/home/student/Desktop/myfifo"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[])
{
    int pipe_fd;
    int result;

    int open_mode_write = O_WRONLY;
    int open_mode_read = O_RDONLY;

    int bytes_written = 0;
    int bytes_read = 0;

    char buffer[BUFFER_SIZE + 1];

    if (access(FIFO_NAME, F_OK) == -1)
    {
        result = mkfifo(FIFO_NAME, 0777);
        if (result == 0)
            printf("FIFO CREATED  \n");
        else
        {
            fprintf(stderr, "Cannot open Pipe %s \n", FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d opening FIFO in O_WRONLY mode \n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode_write);
    printf("Process %d result %d \n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        result = write(pipe_fd, buffer, sizeof(buffer));
        if (result == -1)
        {
            fprintf(stderr, "Write error on pipe \n");
            exit(EXIT_FAILURE);
        }
        bytes_written += result;
    }
    printf("Process %d Writes %d bytes", getpid(), bytes_written);
    close(pipe_fd);

    memset(buffer, 0, sizeof(buffer));
    printf("Process %d opening FIFO in O_RDONLY mode \n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode_read);
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
}
