#include <stdio.h>
#include <stdlib.h>
#define ERR -9999
#define max_size 10

typedef int T;
typedef struct CircularQuque
{
    /* data */
    T arr[max_size];
    int front;
    int rear
} CQ;

int isEmpty(CQ *q)
{
    return q->front == q->rear;
}

int isFull(CQ *q)
{
    return (q->front == (q->rear + 1) % max_size);
}
void Insert(CQ *q, T item)
{
    if (isFull(q))
    {
        printf("Queue UnderFlow");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % max_size;
        q->arr[q->rear] = item;
    }
}

T delete (CQ *q)
{
    if (isEmpty(q))
    {
        printf("Queue Udnerflow");
        return ERR;
    }
    else
    {
        q->front = (q->front + 1) % max_size;
        return (q->arr[q->front]);
    }
}

void Display(CQ *q)
{
    int i;
    printf("\n Queue Contents are \n ");
    for (i = (q->front + 1) % max_size; i != q->rear; i = (i + 1) % max_size)
    {
        printf("%d ->", q->arr[i]);
    }
    printf(" | %d |", q->arr[i]);
}

void main()
{
    CQ q1;
    q1.front = q1.rear = -1;

    int choice, ele;

    while (1)
    {
        printf("\n Enter choice \n");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(&q1))
                printf("Full from isFull");
            else
                printf("Not Full from isFull");
            break;

        case 2:

            if (isEmpty(&q1))
                printf("Empty from isEmpty");
            else
                printf("not Empty from isEmpty");
            break;

        case 3:
            printf("Enter the element to be inserted");
            scanf(" %d", &ele);
            Insert(&q1, ele);
            break;

        case 4:
            delete (&q1);
            break;

        case 5:
            Display(&q1);
            break;
        }
    }
}