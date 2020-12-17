#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[100];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S();
void U();
void V();
void W();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void success()
{
    printf("-------------------------------SUCCESS------------------------------------------\n");
    exit(0);
}

void invalid()
{
    printf("-------------------------------INVALID------------------------------------------\n");
    exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S()
{
    U();
    V();
    W();
}

void U()
{
    if (str[curr] == '(')
    {
        curr++;
        S();
        if (str[curr] == ')')
        {
            curr++;
            return;
        }
        else
            invalid();
    }
    else if (str[curr] == 'a')
    {
        curr++;
        S();
        if (str[curr] == 'b')
        {
            curr++;
            return;
        }
        else
            invalid();
    }
    else if (str[curr] == 'd')
    {
        curr++;
        return;
    }
    else
        invalid();
}

void V()
{
    if (str[curr] == 'a')
    {
        curr++;
        V();
    }
}

void W()
{
    if (str[curr] == 'c')
    {
        curr++;
        W();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    printf("Enter the string to be parsed \n");
    scanf("%s", str);

    S();
    if (str[curr] == '$')
        success();
    else
    {
        printf("String invalid at %c", str[curr]);
        invalid();
        exit(0);
    }
    return 0;
}
