#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1
#define false INT_MIN

void push(int stack[], int item, int *top)
{
    if (*top <= MAX - 1)
        stack[++(*top)] = item;
    else
        printf("Stack overflow for PUSH method");
}
int pop(int stack[], int *top)
{
    if (*top >= 0)
        return (stack[(*top)--]);
    else
    {
        printf("Stack Underflow for POP method");
        return false;
    }
}

void display(int stack[], int top)
{
    for (int i = 0; i < top; i++)
        printf(" &d \t ", stack[i]);
}

void main()
{
    int stack[MAX], top = -1, ch;
    int item;
    printf("Enter 1.Push 2.Pop 3.Display 4.Exit");
    while (1)
    {
        printf("Enter you choice");
        scanf("%d ", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the elements \n");
            scanf("%d", &item);
            push(stack, item, &top);
            break;
        case 2:
            item = pop(stack, &top);
            if (item != false)
                printf("The element popped is %d \n", item);
            break;
        case 3:
            printf("The elements of the stack are \n");
            display(stack, top);
            break;
        default:
            exit(0);
        }
    }
}