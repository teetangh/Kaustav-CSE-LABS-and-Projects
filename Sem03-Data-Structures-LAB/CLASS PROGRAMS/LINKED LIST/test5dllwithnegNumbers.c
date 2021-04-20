#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} * NODE;

NODE insertFront(NODE first, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->llink;
    temp->rlink;

    if (first == NULL)
        return temp;

    // else
    // {
    //     temp
    // }
}
void main()
{
}
