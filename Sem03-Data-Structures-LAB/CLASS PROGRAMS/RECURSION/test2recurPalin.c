#include <stdio.h>
#include <string.h>

int pal(char str[], int l, int h)
{
    if (str[l] != str[h])
        return 0;

    else if (l < h)
        pal(str, ++l, --h);
    return 1;
}
void main()
{
    char str[50];
    int X;
    printf("Enter the string to check palindrome \n");
    gets(str);

    X = pal(str, 0, strlen(str) - 1);
    if (X == 1)
        printf("Palin");
    else
        printf("NOT Palin");
}
