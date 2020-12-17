#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[100];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void E();
void Eprime();
void T();
void Tprime();
void F();

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

void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (str[curr] == '+')
    {
        curr++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (str[curr] == '*')
    {
        curr++;
        F();
        Tprime();
    }
}
void F()
{
    if (str[curr] == '(')
    {
        curr++;
        E();
        if (str[curr] == ')')
        {
            curr++;
            return;
        }
        else
            invalid();
    }
    else if (str[curr] == 'i')
    {
        curr++;
        return;
    }
    else
        invalid();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    printf("Enter the string to be parsed \n");
    scanf("%s", str);

    E();
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
