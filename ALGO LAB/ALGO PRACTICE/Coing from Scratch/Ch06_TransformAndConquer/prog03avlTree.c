// Program given by Algorithms professor

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max2(int a, int b)
{
    return (a < b) ? a : b;
}

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max2(height(y->left), height(y->right));
    x->height = max2(height(x->left), height(x->right));

    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max2(height(x->left), height(x->right));
    y->height = max2(height(y->left), height(y->right));

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    else
        return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    // Base Case
    if (node == NULL)
        return (newNode(key));

    // Recursive Call
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max2(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key < node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf(" %d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the constructed AVL"
           " tree is \n");
    preOrder(root);

    return 0;
}
