#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY, O_CREAT, S_IRUSR | S_IWUSR);

    while (read(in, &c, 1) == 1)
        write(out, &c, 1);

    exit(0);
}
// int main(int argc, char const *argv[])
// {

//     FILE *fp = fopen(argv[1], "r");
//     int out = open(argv[2], O_WRONLY);
//     char ch;

//     if (fp == NULL)
//     {
//         printf("Failed to open");
//         return -1;
//     }

//     while ((ch = fgetc(fp) != EOF))
//         write(out, &ch, 1);

//     return 0;
// }

// // Syntax
// int close(int fildes);