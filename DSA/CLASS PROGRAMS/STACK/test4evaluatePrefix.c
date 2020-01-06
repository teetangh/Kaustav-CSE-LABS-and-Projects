#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
        printf("Stack Overflow\n");
}

char pop(stack *ps)
{
    if (ps->top != -1)
        return ps->arr[(ps->top)--];
    else
        printf("Stack Underflow\n");
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

int eval(char opr, int n1, int n2)
{
    switch (opr)
    {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;

    case '/':
        return n1 / n2;
        break;
    case '^':
    case '$':
        return pow(n1, n2);
    }
}
void main()
{
    stack s1;
    s1.top = -1;

    char prefix[20], symb;
    int i = 0;
    char op1, op2; 
    int result;
    printf("Enter the prefix expression \n");
    gets(prefix);
    strrev(prefix);

    while ((symb = prefix[i++]) != '\0')
    {
        if (isdigit(symb))
        {
            printf("%c ", symb - '0');
            push(&s1, symb);
        }
        else
        {
            op1 = pop(&s1);
            op2 = pop(&s1);
            result = eval(symb, op1, op2);
            push(&s1, result);
        }
        printf("THe result is %d \n", pop(&s1));
    }
}