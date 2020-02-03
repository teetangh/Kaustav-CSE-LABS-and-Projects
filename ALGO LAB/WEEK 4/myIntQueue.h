#include <stdio.h>
#include <stdlib.h>
#define size 10
#define true 1
#define false 0

typedef struct
{
    int arr[size];
    int front;
    int rear;
} queue;

int isEmpty(queue *q);
int isFull(queue *q);
void enqueue(queue *q, int val);
int dequeue(queue *q);
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
    if (q->rear == (size - 1))
        return true;
    else
        return false;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is now full. ");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = val;
    printf("int in enqueue %d \n", q->arr[q->rear]);
}

int dequeue(queue *q)
{
    int x;
    if (isEmpty(q))
    {
        printf("Queue is now Empty. ");
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
        q->arr[q->front++] = 0;
        return x;
    }
}

void display(queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
        printf("%c", q->arr[i]);
}