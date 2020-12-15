// Run Consumer code first then the Producer code
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/home/student/Desktop/my_fifo"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024 * 1024 * 10)

int main(int argc, char const *argv[])
{
    int pipe_fd;
    int res;
    int open_mode_write = O_WRONLY;
    int open_mode_read = O_RDONLY;
    int bytes_sent = 0;
    int buffer;

    if (access(FIFO_NAME, F_OK) == -1)
    {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0)
        {
            fprintf(stderr, "Could not create fifo %s \n", FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d opening FIFO O_WRONLY \n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode_write);
    printf("Process %d result %d \n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        int count = 0;
        while (count < 4)
        {
            scanf("%d", &buffer);
            res = write(pipe_fd, &buffer, sizeof(buffer));
            if (res == -1)
            {
                fprintf(stderr, "Write error on pipe \n");
                exit(EXIT_FAILURE);
            }
            count++;
        }
        (void)close(pipe_fd);
    }
    else
        exit(EXIT_FAILURE);

    int bytes_read = 0;

    printf("Process %d opening FIFO O_RDONLY \n", getpid());

    pipe_fd = open(FIFO_NAME, open_mode_read);
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
}