#include <stdio.h>
#include <stdlib.h>
#define size 5
#define true 1
#define false 0

typedef struct
{
    char arr[size];
    int front;
    int rear;
} queue;

int isEmpty(queue *q);
int isFull(queue *q);
void enqueue(queue *q, char val);
char dequeue(queue *q);
void display(queue *q);

int isEmpty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return true;
    else
        return false;
}
int isFull(queue *q)
{
    if (((q->rear + 1) % size) == q->front)
        return true;
    else
        return false;
}

void enqueue(queue *q, char val)
{
    if (isFull(q))
    {
        printf("CQueue is now full. ");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = ((q->rear + 1) % size);
    }
    q->arr[q->rear] = val;
    printf("char in enqueue %c \n", q->arr[q->rear]);
}

char dequeue(queue *q)
{
    char x;
    if (isEmpty(q))
    {
        printf("CQueue is now Empty. ");
        return -1;
    }
    else if (q->front == q->rear)
    {
        x = q->arr[q->front];
        q->arr[q->front] = 0;
        q->front = q->rear = -1;
        return x;
    }
    else
    {
        x = q->arr[q->front];
        q->arr[q->front] = 0;
        q->front = ((q->front + 1) % size);
        return x;
    }
}

void display(queue *q)
{
    printf("FRONT IS %d \n", q->front);
    printf("REAR IS %d \n", q->rear);
    for (int i = ((q->front) % size); i <= size - 1; i++)
        printf("%c", q->arr[i]);
    printf("\n");
    if (q->front > q->rear)
    {
        for (int i = 0; i <= ((q->rear) % size); i++)
            printf("%c", q->arr[i]);
    }
}

void main()
{
    queue CQ;
    CQ.front = CQ.rear = -1;

    printf("1.isEmpty \n");
    printf("2.isFull \n");
    printf("3.enqueue \n");
    printf("4.dequeue \n");
    printf("5.display \n");

    int ch;

    char val;
    do
    {
        printf("\n Enter your choice \n ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (isEmpty(&CQ))
                printf("Cqueue is empty. ");
            else
                printf("Cqueue is not empty. ");
            break;

        case 2:
            if (isFull(&CQ))
                printf("Cqueue is full. ");
            else
                printf("Cqueue is not full. ");
            break;
        case 3:
            printf("Enter the char value to be enqueued. ");
            scanf(" %c", &val);
            printf("char in main %c \n", val);
            enqueue(&CQ, val);
            break;
        case 4:
            val = dequeue(&CQ);
            printf("Value dequeued from main %c", val);
            break;
        case 5:
            display(&CQ);
            break;
        default:
            break;
        }
    } while (ch <= 5);
}