#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: filename pattern\n");
        exit(0);
    }

    char buffer[1000];
    // int nread;

    int in, out;

    in = open("input_file.in", O_RDONLY);
    out = open("output_file.out", O_WRONLY);

    char c;

    bool line_contains_pattern = false;
    char end_line = '\n';

    int i = 0;
    while (read(in, &c, 1) == 1)
    {
        buffer[i++] = c;
        // printf(" %s | %d \n", buffer , line_contains_pattern);

        if (c == '\n')
        {
            if (line_contains_pattern == true)
                write(out, buffer, strlen(buffer));

            memset(buffer, 0, sizeof(buffer));
            write(out, &end_line, 1);
            line_contains_pattern = false;
            i = 0;
        }

        if (i >= strlen(argv[1]))
        {

            if (strncmp(argv[1], buffer + i - strlen(argv[1]), strlen(argv[1])) == 0)
                line_contains_pattern = true;
        }
    }

    // while (read(in, buffer, strlen(argv[1])))
    // {
    //     if (strcmp(argv[1], buffer) == 0)
    //         write(out, buffer, strlen(argv[1]));

    //     else
    //         continue;
    // }

    return 0;
}
