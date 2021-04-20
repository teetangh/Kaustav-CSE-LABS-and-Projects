#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} * NODE;

NODE insert_frontCDL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->llink = n->rlink = NULL;

    if (first == NULL)
    {
        n->llink = n;
        n->rlink = n;
        return;
    }

    n->llink = first->llink;

    first->llink->rlink = n;
    first->llink = n;
    return n;
}

NODE insert_rearCDL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->rlink = n->llink = NULL;

    if (first == NULL)
    {
        n->llink = n;
        n->rlink = n;
        return;
    }

    first->llink->rlink = n;
    n->llink = first->llink;
    n->rlink = first;
    first->llink = n;

    return first;
}

NODE delete_frontCDL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n ");
        return NULL;
    }

    if (first->llink == first)
    {
        printf("%d deleted", first->data);
        free(first);
        return NULL;
    }

    NODE del = first;

    first->llink->rlink = first->rlink;
    first->rlink->llink = first->llink;

    printf("%d deleted", del->data);

    first = first->rlink;
    free(del);
    return first;
}

NODE delete_rearCDL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return NULL;
    }

    if (first->llink == first)
    {
        printf("%d deleted", first->data);
        free(first);
        return NULL;
    }

    NODE del = first->llink;
    first->llink->llink->rlink = first;
    first->llink = first->llink->llink;

    free(del);
    return first;
}

void display_CDL(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return;
    }

    NODE dum = first; // Dummy Node

    while (dum->rlink != first)
    {
        printf("%d", dum->data);
        dum = dum->rlink;
    }

    printf("%d", dum->data);
}