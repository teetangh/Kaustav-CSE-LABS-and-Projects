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
#define TEN_MEG (1024 * 1024 * 10)

int main(int argc, char const *argv[])
{
    int pipe_fd;
    int result;
    int open_mode = O_WRONLY;

    int bytes_sent = 0;
    char buffer[BUFFER_SIZE + 1];

    if (access(FIFO_NAME, F_OK) == -1)
    {
        result = mkfifo(FIFO_NAME, 0777);
        if (result == -1)
        {
            fprintf(stderr, "Cannot Open Pipe %s\n", FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, O_WRONLY);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        result = write(pipe_fd, buffer, sizeof(buffer));
        if (result == -1)
        {
            fprintf(stderr, "Write Error on pipe\n");
            exit(EXIT_FAILURE);
        }
        bytes_sent += result;

        (void)close(pipe_fd);
    }
    else
        exit(EXIT_FAILURE);

    printf("Process %d Finished \n", getpid());
    exit(EXIT_SUCCESS);
}
