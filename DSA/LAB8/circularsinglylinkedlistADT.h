#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} * NODE;

NODE insert_frontCSL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->next = NULL;

    if (first == NULL)
    {
        n->next = n;
        return n;
    }

    n->next = first;

    NODE last = first;
    while (last->next != first)
        last = last->next;

    last->next = n;

    return n;
}

NODE insert_rearCSL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->next = NULL;

    if (first == NULL)
    {
        n->next = n;
        return n;
    }

    n->next = first;

    NODE last = first;
    while (last->next != first)
        last = last->next;

    last->next = n;

    return first;
}

NODE delete_frontCSL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n ");
        return NULL;
    }

    if (first->next == first)
    {
        printf("%d deleted", first->data);
        free(first);
        return NULL;
    }

    NODE del = first;

    NODE last = first;
    while (last->next != first)
        last = last->next;

    first = first->next;
    last->next = first;

    printf("%d deleted", del->data);
    free(del);

    return first;
}

NODE delete_rearCSL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return NULL;
    }

    if (first->next == first)
    {
        printf("%d deleted", first->data);
        free(first);
        return NULL;
    }

    NODE last = first;
    while (last->next->next != first)
        last = last->next;

    last->next = NULL;
    free(last->next);

    return first;
}

void display_CSL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return;
    }

    NODE dum = first; // Dummy Node

    while (dum->next != first)
    {
        printf("%d", dum->data);
        dum = dum->next;
    }

    printf("%d", dum->data);
}