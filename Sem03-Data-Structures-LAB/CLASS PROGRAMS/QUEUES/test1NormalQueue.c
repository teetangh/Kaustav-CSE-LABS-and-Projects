#include <stdio.h>
#include <stdlib.h>
#define max_size 5
typedef struct
{
    int q[max_size];
    int rear;
    int front;
} Q;

int isEmpty(Q q1)
{
    if (q1.front == -1 || q1.front > q1.rear)
        return 1;
    else
        return 0;
}
int isFull(Q q1)
{
    if (q1.rear == max_size - 1)
        return 1;
    else
        return 0;
}

void addq(Q *q1, int ele)
{
    if (!isFull(*q1))
    {
        q1->rear++;
        if (q1->front == -1)
        {
            q1->front = 0;
            q1->q[q1->rear] = ele;
        }

        else
            q1->q[q1->rear] = ele;
    }
}

int deleteq(Q *q1)
{
    if (q1->front == -1 || q1->front > q1->rear)
        return 0;
    else
        return (q1->q[q1->front++]);
}

int displayq(Q *q1)
{
    int i;
    for (i = q1->front; i != q1->rear; i++)
        printf("| %d |", q1->q[i]);
    printf("| %d |", q1->q[i]);
}

void main()
{
    Q q1;
    q1.front = q1.rear = -1;

    int choice, ele;

    printf("1.isFull \n");
    printf("2.isEmpty \n");
    printf("3.Enqueue \n");
    printf("4.Dequeue \n");
    printf("5.Display \n");
    while (1)
    {
        printf("\n Enter your choice \n");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(q1))
                printf("Full from isFull");
            else
                printf("Not Full from isFull");
            break;

        case 2:

            if (isEmpty(q1))
                printf("Empty from isEmpty");
            else
                printf("not Empty from isEmpty");
            break;

        case 3:
            printf("Enter the element to be inserted");
            scanf(" %d", &ele);
            addq(&q1, ele);
            break;

        case 4:
            deleteq(&q1);
            break;

        case 5:
            displayq(&q1);
            break;
        }
    }
}