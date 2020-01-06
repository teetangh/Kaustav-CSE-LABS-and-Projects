#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} * NODE;

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

NODE insertFront(NODE first, int ele)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));

    n->data = ele;
    n->next = NULL;

    if (first == NULL)
        return n;

    n->next = first;
    return n;
}

NODE insertRear(NODE first, int ele)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("Memory not found \n");
        exit(0);
    }

    n->data = ele;
    n->next = NULL;

    if (first == NULL)
        return n;

    NODE last = first;

    while (last->next != NULL)
        last = last->next;

    last->next = n;
    return first;
}

NODE deleteFront(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty");
        return first;
    }

    NODE temp = first;
    first = first->next;

    printf("The element deleted is %d ", temp->data);
    free(temp);

    return first;
}
NODE deleteRear(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty");
        return first;
    }

    NODE prev = NULL, last = first;

    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }

    if (prev == NULL)
        return NULL;

    else
    {
        free(last);
        prev->next = NULL;
        return first;
    }
}
