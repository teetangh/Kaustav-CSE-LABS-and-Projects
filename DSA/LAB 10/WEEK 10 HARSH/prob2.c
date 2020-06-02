#include <stdio.h>

#include <string.h>

#include <stdlib.h>

typedef struct node

{

    int data;

    struct node *lchild, *rchild;

} * NODE;

NODE create_BT(NODE root, int ele, char path[])

{

    int i = 0;

    NODE n = (NODE)malloc(sizeof(struct node));

    n->data = ele;

    n->lchild = NULL;

    n->rchild = NULL;

    NODE t = root;

    NODE prev = t;

    while (path[i] != '\0' && t != NULL)

    {

        if (path[i] == 'L' || path[i] == 'l')

        {

            prev = t;

            t = t->lchild;
        }

        else if (path[i] == 'R' || path[i] == 'r')

        {

            prev = t;

            t = t->rchild;
        }

        i = i + 1;
    }

    if (t != NULL || path[i] != '\0')

    {

        printf("\n****INVALID PATH****\n");

        free(n);

        return root;
    }

    if (path[i - 1] == 'L' || path[i] == 'l')

    {

        prev->lchild = n;
    }

    else

    {

        prev->rchild = n;
    }

    return root;
}

void itpreorder(NODE root)

{

    if (root == NULL)

    {

        printf("*********EMPTY TREE************\n");

        return;
    }

    NODE st[50];

    int top = -1;

    while (1)

    {

        while (root != NULL)

        {

            printf("%d ", root->data);

            st[++top] = root;

            root = root->lchild;
        }

        if (top != -1)

        {

            root = st[top--];

            root = root->rchild;
        }

        else

        {

            return;
        }
    }
}

void itinorder(NODE root)

{

    if (root == NULL)

    {

        printf("*********EMPTY TREE************\n");

        return;
    }

    NODE st[50];

    int top = -1;

    while (1)

    {

        while (root != NULL)

        {

            st[++top] = root;

            root = root->lchild;
        }

        if (top != -1)

        {

            root = st[top--];

            printf("%d ", root->data);

            root = root->rchild;
        }

        else

        {

            return;
        }
    }
}

void itpostorder(NODE root)

{

    if (root == NULL)

    {

        printf("************EMPTY TREE*************\n");

        return;
    }

    int top = -1;

    struct stack

    {

        NODE addr;

        int flag;

    } s[50];

    while (1)

    {

        while (root != NULL)

        {

            s[++top].addr = root;

            root = root->lchild;

            s[top].flag = 1;
        }

        while (s[top].flag == 0)

        {

            root = s[top--].addr;

            printf("%d ", root->data);

            if (top == -1)

            {

                return;
            }
        }

        root = s[top].addr;

        root = root->rchild;

        s[top].flag = 0;
    }
}

void itlevelorder(NODE root)

{

    if (root == NULL)

    {

        printf("************EMPTY LIST*************\n");

        return;
    }

    NODE q[50];

    int f = -1;

    int r = -1;

    q[++r] = root;

    f = 0;

    while (f <= r)

    {

        root = q[f++];

        printf("%d ", root->data);

        if (root->lchild)
            q[++r] = root->lchild;

        if (root->rchild)
            q[++r] = root->rchild;
    }
}

int main()

{

    NODE root = (NODE)malloc(sizeof(struct node));

    printf("INSERT ROOT ELEMENT: ");

    scanf("%d", &(root->data));

    root->lchild = NULL;

    root->rchild = NULL;

    char path[20];

    int ch;

    do

    {

        printf("\nINPUT YOUR CHOICE:");

        printf("\n1.INSERT\t2.DISPLAY\n");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:

            printf("INPUT THE ELEMENT TO INSERT:");

            int ele;

            scanf("%d", &ele);

            printf("INPUT THE PATH:");

            scanf("%s", path);

            fflush(stdin);

            root = create_BT(root, ele, path);

            break;

        case 2:

            printf("\nDISPLAYING ELEMENTS:\n");

            break;
        }

    } while (ch != 2);

    printf("DISPLAYING IN IN ORDER: \t");

    itinorder(root);

    printf("\n");

    printf("DISPLAYING IN PRE ORDER:\t");

    itpreorder(root);

    printf("\n");

    printf("DISPLAYING IN POST ORDER:\t");

    itpostorder(root);

    printf("\n");

    printf("DISPLAYING IN LEVEL ORDER:\t");

    itlevelorder(root);

    printf("\n");
}