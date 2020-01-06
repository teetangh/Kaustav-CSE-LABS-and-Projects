#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} * NODE;

NODE recursiveCreateBinaryTree()
{
    NODE temp;
    int ele;

    printf("Enter the element to be inserted(-1 for no data):");
    scanf("%d", &ele);

    if (ele == -1)
        return NULL;
    temp = (NODE)malloc(sizeof(struct node));

    temp->data = ele;

    printf("Enter lchild child of %d: \n ", ele);
    temp->lchild = recursiveCreateBinaryTree();

    printf("Enter rchild child of %d: \n ", ele);
    temp->rchild = recursiveCreateBinaryTree();

    return temp;
}

void inorder(NODE ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%5d", ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(NODE ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%5d", ptr->data);
    }
}

void preorder(NODE ptr)
{
    if (ptr != NULL)
    {
        printf("%5d", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
