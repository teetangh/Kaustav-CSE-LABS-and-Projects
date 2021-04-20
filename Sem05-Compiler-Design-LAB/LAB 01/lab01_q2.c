#include <stdio.h>
#include <stdlib.h> // For exit()
#include <stdbool.h>
int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;
    printf("Enter the filename to open for reading: \n");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    // Open one file for reading
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(2);
    }

    printf("Enter the filename to open for writing: \n");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w+"); // Open another file for writing

    fseek(fptr1, 1, SEEK_END);
    // fputc(getc(fptr1), fptr2);

    while (!fseek(fptr1, -2, SEEK_CUR))
    {
        fputc(getc(fptr1), fptr2);
    }

    return 0;
}