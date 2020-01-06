#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define true 1
#define false 0

typedef struct
{
    int arr[MAX];
    int top;
} stack;

//Push Operation
void push(stack *ps, int item)
{

    if (ps->top == MAX - 1)
    {
        printf("stack Overflow\n");
        return;
    }
    else
    {
        ps->arr[++(ps->top)] = item;
        return;
    }
}

//Pop operation
int pop(stack *ps)
{
    int item;
    if (ps->top == -1)
    {
        printf("stack Underflow\n");
        return -1;
    }
    else
    {
        item = ps->arr[ps->top--];
        printf("Item popped is %d\n", item);
        return item;
    }
}

void display(stack *ps)
{
    printf("Elements in the stack are:\n");
    for (int i = ps->top; i >= 0; i--)
    {
        /* code */
        printf("%d\n", ps->arr[i]);
    }
}

void isFull(stack *ps)
{
    if (ps->top == MAX - 1)
    {
        printf("stack Overflow\n");
        return;
    }
}
void isEmpty(stack *ps)
{
    if (ps->top == -1)
    {
        printf("stack Empty\n");
        return;
    }
}
