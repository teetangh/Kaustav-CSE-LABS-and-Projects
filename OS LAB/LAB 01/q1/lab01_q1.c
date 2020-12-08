#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        printf(" USAGE: filename pattern \n");
        return 0;
    }
    // Prereqs
    char ch;
    char buffer[100];

    int in, out;

    in = open("input.txt", O_RDONLY);
    out = open("output.txt", O_WRONLY);

    // int line_no = 0;
    int pattern_length = strlen(argv[1]);

    int i = 0;

    bool flag = false;
    char end_line = '\n';
    while (read(in, &ch, 1) == 1)
    {
        // printf(" %d", i);
        if (ch == '\n')
        {
            // line_no++;
            if (flag == true)
                write(out, buffer, strlen(buffer));
            write(out, &end_line, 1);
            i = 0;
            flag = false;
            memset(buffer, '\0', sizeof(buffer));
        }
        else
        {
            buffer[i] = ch;
            if ((i >= pattern_length) && (strcmp(argv[1], buffer + strlen(buffer) - pattern_length) == 0))
                flag = true;
            i++;
        }
    }
    write(out, buffer, strlen(buffer));
    return 0;
}
