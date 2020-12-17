#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[100];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S();
void T();
void Tprime();

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
    if (str[curr] == 'a' || str[curr] == '>')
    {
        curr++;
        return;
    }
    else if (str[curr] == '(')
    {
        curr++;
        T();
        if (str[curr] == ')')
        {
            curr++;
            return;
        }
        else
            invalid();
    }
    else
        invalid();
}

void T()
{
    S();
    Tprime();
}
void Tprime()
{
    if (str[curr] == ',')
    {
        curr++;
        S();
        Tprime();
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
