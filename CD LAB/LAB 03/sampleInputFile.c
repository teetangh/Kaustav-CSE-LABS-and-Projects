// Solved problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ca, cb;
    char buff[100];
    int k = 0;
    FILE *fa = fopen("sampleInputFile.c", "r");
    if (fa == NULL)
    {
        printf("Cannot open the file\n");
        exit(0);
    }
    ca = getc(fa);
    while (ca != EOF)
    {
        k = 0;
        if (ca == '=')
        {
            buff[k++] = ca;
            cb = getc(fa);
            if (cb == '=')
            {
                buff[k++] = cb;
                buff[k++] = '\0';
                printf("Relational operator %s\n", buff);
            }
            else
            {
                buff[k++] = '\0';
                printf("Assignment operator\n");
            }
        }
        else
        {
            if (ca == '<' || ca == '>' || ca == '!')
            {
                buff[k++] = ca;
                cb = getc(fa);
                if (cb == '=')
                {
                    buff[k++] = cb;
                }
                buff[k++] = '\0';
                printf("Relational operator %s\n", buff);
            }
            else
            {
                buff[k++] = '\0';
            }
        }
        ca = getc(fa);
    }
    return 0;
}