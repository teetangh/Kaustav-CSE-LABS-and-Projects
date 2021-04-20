#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define true 1
#define false 0

typedef struct
{
    int arr[MAX];
    int top;
} stack;

void push(stack *ps, int x)
{
    if (ps->top != MAX - 1)
        ps->arr[++(ps->top)] = x;
    else
        printf("Stack Overflow");
}

int pop(stack *ps)
{
    if (ps->top != -1)
        return ps->arr[(ps->top)--];
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

int full(stack *ps)
{
    if (ps->top == MAX - 1)
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

void main()
{
    stack s;
    s.top = -1;
    int num;

    printf("Enter Number \n ");
    scanf("%d", &num);

    while (num != 0)
    {
        /* code */
        if (!full(&s))
        {
            push(&s, (num % 2));
            num = num / 2;
        }
        else
        {
            printf("Stack Overflow from main");
            exit(0);
        }
    }

    while (!empty(&s))
    {
        num = pop(&s);
        printf("%d", num);
    }
}
