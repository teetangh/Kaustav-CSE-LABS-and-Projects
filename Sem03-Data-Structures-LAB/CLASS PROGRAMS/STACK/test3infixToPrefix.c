#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define true 1
#define false 0

typedef struct
{
    char arr[MAX];
    int top;
} stack;

void push(stack *ps, char x)
{
    if (ps->top != MAX - 1)
        ps->arr[++(ps->top)] = x;
    else
        printf("Stack Overflow");
}

char pop(stack *ps)
{
    if (ps->top != -1)
        return ps->arr[(ps->top)];
    else
        printf("Stack Underflow");
}

int empty(stack *ps)
{
    if (ps->top == -1)
        return true;
    else
        return false;
}

void display(stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        printf(" %c \t ", s.arr[i]);
    }
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
void main()
{
    char infix[20], prefix[20], symb, ele;
    int i = 0, p = 0;

    stack s1;
    s1.top = -1;
    push(&s1, '#');

    printf("Enter the infix expression \n");
    scanf("%s", infix);

    strrev(infix);

    while ((symb = infix[i++]) != '\0')
    {
        printf("C=%c\t", symb);

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
            while (s1.arr[s1.top] > pre(symb))
                prefix[p++] = pop(&s1);
            push(&s1, symb);
            break;
        case '$':
            if (s1.arr[s1.top] == '$')
                prefix[p++] = pop(&s1);
            push(&s1, symb);
            // case '^':
            break;
        default:
            prefix[p++] = symb;
            break;
        }
    }

    while (s1.arr[s1.top] != '#')
        prefix[p++] = pop(&s1);

    prefix[i] = '\0';
    strrev(infix);
    strrev(prefix);

    printf("%s infix is equivalent to prefix %s", infix, prefix);
}