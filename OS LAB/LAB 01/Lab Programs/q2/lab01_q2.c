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

    int line_no = 0;

    int in = open(argv[1], O_RDONLY);

    while (read(in, &ch, 1) == 1)
    {
        if (ch == '\n')
            line_no++;

        printf("%c", ch);

        if (line_no == 20)
        {

            while (read(0, &ch, 1) != 1)
                ;
            line_no = 0;
        }
    }

    return 0;
}
