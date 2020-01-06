#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} * NODE;

NODE insert_frontDL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->rlink = NULL;
    n->llink = NULL;

    if (first == NULL)
        return n;

    n->rlink = first;
    first->llink = n;
    return n;
}

NODE insert_rearDL(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->rlink = NULL;
    n->llink = NULL;

    if (first == NULL)
        return n;

    NODE curr = first;

    while (curr->rlink != NULL)
        curr = curr->rlink;

    curr->rlink = n;
    n->llink = curr;

    return first;
}

NODE delete_rearDL(NODE first)
{
    //Does not handle single node case
    if (first == NULL)
    {
        printf("Empty List \n");
        return first;
    }
    if (first->rlink == NULL)
    {
        NODE curr = first;
        printf("%d deleted \n", curr->data);
        free(curr);
        return first;
    }

    NODE curr = first;

    while (curr->rlink != NULL)
        curr = curr->rlink;

    curr->llink->rlink = NULL;
    printf("%d deleted \n", curr->data);
    free(curr);
    return first;
}

NODE delete_frontDL(NODE first)
{
    if (first == NULL)
    {
        printf("Empty List \n");
        return first;
    }

    if (first->rlink == NULL)
    {
        printf("%d deleted \n ", first->data);
        free(first);
        return NULL;
    }

    NODE X = first;
    first = first->rlink;
    printf("%d", X->data);
    free(X);
    return first;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("List is Empty \n");
        return;
    }

    while (first != NULL)
    {
        printf("%d \t", first->data);
        first = first->rlink;
    }
}