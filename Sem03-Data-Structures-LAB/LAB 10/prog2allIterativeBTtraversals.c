#include <stdio.h>
#include <stdlib.h>
#include "binarytreeADT.h"

struct stack //no typedef here remember
{
    NODE addr;
    int flag;
} s[50];
void iterativePreorder(NODE root)
{
    if (root == NULL)
    {
        printf("Empty \n");
        return;
    }

    NODE stck[50];
    int top = -1;

    while (1)
    {
        while (root != NULL)
        {
            printf(" %d ", root->data);
            stck[++top] = root;
            root = root->lchild;
        }

        if (top != -1)
        {
            root = stck[top--];
            root = root->rchild;
        }

        else
            return;
    }
}

void iterativeInorder(NODE root)
{
    // printf("DEBUG 1 \n");
    if (root == NULL)
    {
        printf("Tree is Empty \n");
        return;
    }
    // printf("DEBUG 2 \n");

    NODE stck[50];
    int top = -1;

    while (1)
    {
        while (root)
        {
            // printf("DEBUG 3 \n");
            stck[++top] = root;
            root = root->lchild;
            // printf("DEBUG 4 \n");
        }
        // printf("DEBUG 5 \n");

        if (top != -1)
        {
            // printf("DEBUG 6 \n");
            root = stck[top--];
            printf(" %d ", root->data);
            root = root->rchild;
            // printf("DEBUG 7 \n");
        }

        else
            return;
    }
}

void iterativePostorder(NODE root)
{

    int top = -1;

    if (root == NULL)
    {
        printf("List Empty");
        return;
    }

    while (1)
    {
        while (root != NULL)
        {
            top++;
            s[top].addr = root;
            s[top].flag = 1;
            root = root->lchild;
        }

        while (s[top].flag == 0)
        {
            root = s[top].addr;
            top--;
            printf(" %d ", root->data);
            if (top == -1)
                return;
        }

        root = s[top].addr;
        root = root->rchild;
        s[top].flag = 0;
    }
}
void main()
{
    NODE stck[50];
    NODE root = recursiveCreateBinaryTree();
    printf(" \n Iterative Inorder \n");
    iterativeInorder(root);
    printf("\n Iterative Preorder \n");
    iterativePreorder(root);
    printf("\n Iterative Postorder \n");
    iterativePostorder(root);
}