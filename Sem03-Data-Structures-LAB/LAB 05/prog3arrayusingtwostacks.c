#include <stdio.h>
#define size 10

typedef struct arrayusingtwostacks
{
    int arr[size];
    int top1;
    int top2;
} TwoStacks;

void push1(TwoStacks *ts, int item)
{
    if ((ts->top1) >= ((ts->top2) - 1))
    {
        printf("stack 1 Overflow\n");
        return;
    }
    else
    {
        ts->arr[++(ts->top1)] = item;
        return;
    }
}
void push2(TwoStacks *ts, int item)
{
    if ((ts->top1) >= ((ts->top2) - 1))
    {
        printf("stack  2 Overflow\n");
        return;
    }
    else
    {
        ts->arr[--(ts->top2)] = item;
        return;
    }
}

int pop1(TwoStacks *ts)
{
    int item;
    if ((ts->top1) <= 0)
    {
        printf("Stack 1 Underflow \n");
        return -1;
    }
    else
    {
        item = ts->arr[(ts->top1)];
        ts->arr[(ts->top1)--] = -1;
        printf("Item popped is %d\n", item);
        return item;
    }
}
int pop2(TwoStacks *ts)
{
    int item;
    if ((ts->top2) >= size - 1)
    {
        printf("Stack 2 Underflow \n");
        return -1;
    }
    else
    {
        item = ts->arr[(ts->top2)];
        ts->arr[(ts->top2)++] = -1;
        printf("Item popped is %d\n", item);
        return item;
    }
}

void display(TwoStacks *ts)
{
    printf("Top1 is at %d \nTop2 is at %d \n", (ts->top1), (ts->top2));
    printf("Elements in TwoStacks are:\n");
    for (int i = 0; i < (ts->top1); i++)
    {
        printf("%d element is %d\n", i, ts->arr[i]);
    }
    for (int i = (ts->top1); i <= size - 1; i++)
    {
        printf("%d element is %d\n", i, ts->arr[i]);
    }
}

void isFull(TwoStacks *ts)
{
    if ((ts->top1) >= ((ts->top2) - 1))
    {
        printf("stack Overflow\n");
        return;
    }
}
void isEmpty(TwoStacks *ts)
{
    if ((ts->top1) <= 0 && (ts->top2) >= size - 1)
    {
        printf("stack Empty\n");
        return;
    }
}

void main()
{
    TwoStacks TS;
    TS.top1 = -1;
    TS.top2 = size;

    int choice;
    int item;

    printf("Enter 1 for Push1 \n");
    printf("Enter 2 for Push2 \n");
    printf("Enter 3 for Pop1 \n");
    printf("Enter 4 for Pop2 \n");
    printf("Enter 5 for is Full and is Empty \n");
    printf("Enter 6 for display \n");
    printf("Enter 7 for exit \n");

    do
    {
        printf("Enter your choice\n");

        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Please enter the integer to push\t");
            scanf(" %d", &item);
            push1(&TS, item);
            break;
        case 2:

            printf("Please enter the integer to push\t");
            scanf(" %d", &item);
            push2(&TS, item);
            break;
        case 3:
            pop1(&TS);
            break;
        case 4:
            pop2(&TS);
            break;
        case 5:
            isFull(&TS);
            isEmpty(&TS);
            break;
        case 6:
            display(&TS);
            break;
        case 7:
            break;

        default:
            printf("\n Invalid Choice \n");
            break;
        }

    } while (choice < 7);
}
