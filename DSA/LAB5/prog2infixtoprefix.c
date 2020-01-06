#include "CharStack.h"

char *strrev(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int pre(char symb)
{
    switch (symb)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 3;

    case '$':
    case '^':
        return 4;
    }
}

int main()
{
    char infix[20], prefix[20], symb, ele;
    int i = 0, p = 0;

    stack s1;
    s1.top = -1;
    push(&s1, '#');

    printf("Enter the infix \n");
    scanf("%s", infix);

    strrev(infix); //reverses the infix expressison

    while ((symb = infix[i++]) != '\0')
    {
        //symb=infix[i];
        printf("C=%c\t \n", symb);
        switch (symb)
        {
        case ')':
            push(&s1, ')');
            break;

        case '(':
            while (s1.arr[s1.top] != ')')
                prefix[p++] = pop(&s1);
            ele = pop(&s1);
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            while (pre(s1.arr[s1.top]) > pre(symb))
                prefix[p++] = pop(&s1);
            push(&s1, symb);
            break;
        case '$':
            while ((s1.arr[s1.top]) == '$')
                prefix[p++] = pop(&s1);
            push(&s1, symb);
            break;
        default:
            prefix[p++] = symb;
            break;
        }
        //i++;
    }

    while (s1.arr[s1.top] != '#')
        prefix[p++] = pop(&s1);

    prefix[i] = '\0';
    strrev(infix);
    strrev(prefix);

    printf("infix %s is same as prefix %s\n", infix, prefix);
}