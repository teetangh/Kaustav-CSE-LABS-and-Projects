#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} * NODE;

void insert_rear(NODE *front, NODE *rear, int ele)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));

    if (n != NULL)
    {
        n->data = ele;
        n->next = NULL;
    }

    if (*front == NULL)
        *front = *rear = n;

    else
    {
        (*rear)->next = n;
        (*rear) = (*rear)->next;
    }
}

void delete_front(NODE *front, NODE *rear)
{
    if (*front == NULL)
    {
        printf("Queue is Empty \n");
        *rear = NULL;
        return;
    }

    if ((*front)->next == NULL)
    {
        free(front);
        *front = *rear = NULL;
        return;
    }

    NODE temp = (*front);

    printf("The element deleted is %d \n", temp->data);
    (*front) = (*front)->next;
    free(temp);
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return;
    }

    while (first != NULL)
    {
        /* code */
        printf("%d ->", first->data);
        first = first->next;
    }
}

void main()
{
    NODE first = NULL;
    NODE rear = NULL;
    int choice, ele;

    printf("1. Insert Rear \n");
    printf("2. Delete Front \n");
    printf("3. Display. \n");

    do
    {
        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the element \n");
            scanf("%d", &ele);

            insert_rear(&first, &rear, ele);
            break;

        case 2:
            delete_front(&first, &rear);
            break;

        case 3:
            printf("The elements in the list are: \n");
            display(first);
            break;
        }

    } while (choice < 4);
}
