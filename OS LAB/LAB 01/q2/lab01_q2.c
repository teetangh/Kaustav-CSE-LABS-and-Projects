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
    int fp;
    fp = open(argv[1], O_RDONLY);

    char ch;

    int lines = 0;
    while (read(fp, &ch, 1) == 1)
    {
        if (ch == '\n')
            lines++;

        printf("%c", ch);

        if (lines == 20)
        {

            while (read(0, &ch, 1) != 1)
                ;
            lines = 0;
        }
    }

    return 0;
}
