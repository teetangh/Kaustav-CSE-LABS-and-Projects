#include <stdio.h>
#include <stdlib.h>
#include "binarytreeADT.h"

void main()
{
    int n, x, choice;
    NODE root = NULL;

    while (1)
    {
        printf("\n OUTPUT \n ");
        printf("1. Insert 2.All traversals 3.Exit \n ");
        printf("Enter your choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = recursiveCreateBinaryTree();
            break;
        case 2:
            printf("\n Inorder Traversals \n");
            inorder(root);
            printf("\n Postorder Traversals \n");
            postorder(root);
            printf("\n Preorder Traversals \n");
            preorder(root);
            printf("\n ********* \n");
            break;
        case 3:
            exit(0);
        }
    }
}