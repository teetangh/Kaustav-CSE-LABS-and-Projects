#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fptr;
    fptr = fopen("example.bin", "wb+");
    int num1 = 0;
    int num2 = 0;

    for (int i = 1; i <= 4; i++)
    {
        scanf(" %d", &num1);
        fwrite(&num1, sizeof(int), 1, fptr);
    }

    printf("Write Finsihed ! \n");
    fclose(fptr);
    fptr = fopen("example.bin", "rb");

    for (int i = 1; i <= 4; i++)
    {
        fread(&num2, sizeof(int), 1, fptr);
        printf(" %d \n", num2);
    }

    printf("Read Finished !!\n");
    return 0;
}
