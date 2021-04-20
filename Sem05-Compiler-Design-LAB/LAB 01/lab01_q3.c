#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    FILE *fa, *fb, *fc;
    fa = fopen("file1.txt", "r");
    fb = fopen("file2.txt", "r");
    fc = fopen("merge.txt", "w+");

    int ch1, ch2;

    int counter = 0;
    char buffer[1000];

    while (true)
    {
        memset(buffer, 0, strlen(buffer));

        if (counter % 2 == 0)
        {
            if (fgets(buffer, 100, fa) != NULL)
                fputs(buffer, fc);
            else
                break;
        }
        else
        {
            if (fgets(buffer, 100, fb) != NULL)
                fputs(buffer, fc);
            else
                break;
        }
        counter++;
    }

    while (fgets(buffer, 100, fa) != NULL)
        fputs(buffer, fc);

    while (fgets(buffer, 100, fb) != NULL)
        fputs(buffer, fc);

    return 0;
}
