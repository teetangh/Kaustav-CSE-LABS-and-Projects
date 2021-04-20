#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} * Nodeptr;

int max2(int a, int b)
{
    int c = (a > b) ? a : b;
    return c;
}

int max3(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

Nodeptr recursiveCreateBinaryTree()
{
    Nodeptr temp;
    int ele;

    printf("Enter the element to be inserted(-1 for no data):");
    scanf("%d", &ele);

    if (ele == -1)
        return NULL;

    temp = (Nodeptr)malloc(sizeof(struct node));

    temp->data = ele;

    printf("Enter lchild child of %d: \n ", ele);
    temp->lchild = recursiveCreateBinaryTree();

    printf("Enter rchild child of %d: \n ", ele);
    temp->rchild = recursiveCreateBinaryTree();

    return temp;
}
int numberOfNodesBinaryTree(Nodeptr root)
{
    int leftValue = 0;
    int rightValue = 0;
    if (root == NULL)
        return 0;
    else
    {
        /* code */
        leftValue = numberOfNodesBinaryTree(root->lchild);
        rightValue = numberOfNodesBinaryTree(root->rchild);
        return leftValue + rightValue + 1;
    }
}

int heightOfBinaryTree(Nodeptr root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max2(heightOfBinaryTree(root->lchild), heightOfBinaryTree(root->lchild));
}
int diameterOfBinaryTree(Nodeptr root)
{
    if (root == NULL)
        return 0;

    int option1 = heightOfBinaryTree(root->lchild) + heightOfBinaryTree(root->rchild);
    int option2 = diameterOfBinaryTree(root->lchild);
    int option3 = diameterOfBinaryTree(root->rchild);

    return max2(option1, max2(option2, option3));
}
void main()
{
    Nodeptr root = NULL;

    printf("Enter 0.createBinaryTree(Recursive) \n");
    printf("Enter 1.numberOfNodes(Recursive) \n");
    printf("Enter 2.HeightOfBinaryTree(Recursive) \n");
    printf("Enter 3.DiamterOfBianryTree(Recursive) \n");

    int choice;
    printf("Enter your choice\n");
    scanf(" %d", &choice);

    int tempvalue, item;
    int numberOfNodes, height, diameter;
    while (1)
    {

        switch (choice)
        {
        case 0:
            root = recursiveCreateBinaryTree();
            break;
        case 1:
            numberOfNodes = numberOfNodesBinaryTree(root);
            printf("\nNumber of Nodes are: %d\n", numberOfNodes);
            break;
        case 2:
            height = heightOfBinaryTree(root);
            printf("\nHeight of Bianry Tree is : %d\n", height);
            break;
        case 3:
            diameter = diameterOfBinaryTree(root);
            printf("\nDiamter of Bianry Tree is : %d\n", diameter);
            break;

        default:
            exit(0);
            break;
        }

        printf("Enter your choice\n");
        scanf(" %d", &choice);
    }
}
