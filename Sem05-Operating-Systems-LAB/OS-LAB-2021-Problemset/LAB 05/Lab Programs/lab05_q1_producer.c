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
    int n, pipe_fd;
    char buffer[BUFFER_SIZE];
    int open_mode = O_WRONLY;
    int curr_number;

    if (access(PIPE_NAME, F_OK) == -1)
    {
        int res = mkfifo(PIPE_NAME, 0777);
        if (res != 0)
        {
            fprintf(stderr, "Pipe createion failed \n");
            exit(1);
        }
        else
            printf("Pipe created successfully \n");
    }

    printf("Process %d opening FIFO O_WRONLY \n", getpid());
    pipe_fd = open(PIPE_NAME, open_mode);
    printf("Process %d result %d \n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {

        printf("Enter the four intgers \n");
        for (int i = 0; i < 4; i++)
        {
            scanf(" %d", &curr_number);
            write(pipe_fd, &curr_number, 1);
        }
        (void)close(pipe_fd);
    }
    exit(EXIT_SUCCESS);
}
