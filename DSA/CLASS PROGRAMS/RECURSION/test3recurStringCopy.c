#include <stdio.h>
// #include <string.h>

int copy(char a[], char b[], int i)
{
    if (b[i] != '\0')
    {
        a[i] = b[i];
        copy(a, b, i + 1);
    }
    else
        return 0;
}
void main()
{
    char str[20];
    char st[20];
    printf(" Enter string to be copied \n");
    gets(st);

    copy(str, st, 0);
    printf(" string  copied \n");
    puts(str);
}
