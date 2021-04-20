#include <stdio.h>
#include <stdlib.h>
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

void main()
{
    stack s;
    s.top = -1;

    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    pop(&s);
    display(s);
}
