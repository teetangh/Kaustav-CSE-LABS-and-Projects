#include <stdio.h>
#include <string.h>
void checkKeyword(char A[], int a, int b)
{
    char Keyword[13][10] = {"int", "main", "include", "case", "char", "long", "short", "for",
                            "do", "while", "return", "void", "FILE"};
    int i;
    for (i = 0; i < 13; i++)
    {
        if (strcmp(A, Keyword[i]) == 0)
        {
            for (int j = 0; A[j] != '\0'; j++)
            {
                if (A[j] >= 'a' && A[j] <= 'z')
                {
                    A[j] = A[j] - 32;
                }
            }
            printf("\n %s \t %d \t %d", A, a, b - (int)strlen(A) - 1);
        }
    }
}
int main()
{
    FILE *fa;
    int ca, l, c, i;
    char word[50];

    l = 1;
    c = 1;

    fa = fopen("eg1.c", "r");
    printf("KeyWord\tLine\tColumn");

    ca = getc(fa);
    while (ca != EOF)
    {
        i = 0;
        while (ca != ' ' && ca != '\n' && ca != EOF && ca != '\t')
        {
            word[i] = ca;
            i++;
            ca = getc(fa);
            c++;
        }
        checkKeyword(word, l, c);
        memset(word, 0, 50);
        if (ca == '\n')
        {
            l++;
            c = 1;
        }
        if (ca == EOF)
            break;
        ca = getc(fa);
        c++;
        if (ca == '\n')
        {
            l++;
            c = 1;
        }
    }
    fclose(fa);
    printf("\n");
    return 0;
}