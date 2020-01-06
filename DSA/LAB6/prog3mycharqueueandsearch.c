#include <stdio.h>
#include <stdlib.h>
#include "mycharqueuefun.h"

void search(queue *q, char key)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->arr[i] == key)
            printf("char %c found at location %d ", q->arr[i], (i + 1));
    }
}
void main()
{
    queue Q;
    Q.front = Q.rear = -1;

    printf("1.isEmpty \n");
    printf("2.isFull \n");
    printf("3.enqueue \n");
    printf("4.dequeue \n");
    printf("5.display \n");
    printf("6.search element \n");

    int ch;
    char key;

    char val;
    do
    {
        printf("\n Enter your choice \n ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (isEmpty(&Q))
                printf("queue is empty. ");
            else
                printf("queue is not empty. ");
            break;

        case 2:
            if (isFull(&Q))
                printf("queue is full. ");
            else
                printf("queue is not full. ");
            break;
        case 3:
            printf("Enter the char value to be enqueued. ");
            scanf(" %c", &val);
            printf("char in main %c \n", val);
            enqueue(&Q, val);
            break;
        case 4:
            val = dequeue(&Q);
            printf("Value dequeued from main %c", val);
            break;
        case 5:
            display(&Q);
            break;

        case 6:
            printf("Enter the element to be searched");
            scanf(" %c", &key);
            search(&Q, key);
            break;
        default:
            break;
        }
    } while (ch <= 6);
}