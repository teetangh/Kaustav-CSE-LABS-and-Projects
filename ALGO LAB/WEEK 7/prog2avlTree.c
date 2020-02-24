#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	int height;
} * Nodeptr;

int max2(int a, int b)
{
	int c = (a > b) ? a : b;
	return c;
}

int height(Nodeptr root)
{
	if (!root)
		return 0;
	else
		return root->height;
}

Nodeptr newNode(int key)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
	temp->data = key;
	temp->lchild = temp->rchild = NULL;
	temp->height = 1;

	return temp;
}

Nodeptr rightRotate(Nodeptr y)
{
	// Assign temp orientations to unbalanced BST
	Nodeptr x = y->lchild;
	Nodeptr T2 = x->rchild;

	// Perform the rotation
	x->rchild = y;
	y->lchild = T2;

	// Update heights

	y->height = max2(height(y->lchild), height(y->rchild)) + 1;
	x->height = max2(height(x->lchild), height(x->rchild)) + 1;

	return x;
}

Nodeptr leftRotate(Nodeptr x)
{
	// Assign temp orientations to unbalanced BST
	Nodeptr y = x->lchild;
	Nodeptr T2 = y->lchild;

	// Perform the rotation
	y->lchild = x;
	x->rchild = T2;

	// Update heights
	x->height = max2(height(x->lchild), height(x->rchild)) + 1;
	y->height = max2(height(y->lchild), height(y->rchild)) + 1;

	return x;
}

int getBalance(Nodeptr N)
{
	if (N == NULL)
		return 0;
	else
		return (height(N->lchild) - height(N->lchild));
}

Nodeptr insert(Nodeptr node, int key)
{
	if (node == NULL)
		return (newNode(key));

	if (key < node->data)
		node->lchild = insert(node->lchild, key);

	else if (key > node->data)
		node->rchild = insert(node->rchild, key);
	else
		return node;

	node->height = 1 + max2(height(node->lchild), height(node->rchild));
	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && key < node->lchild->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->rchild->data)
		return leftRotate(node);

	//Left Right Case
	if (balance > 1 && key > node->lchild->data)
	{
		node->lchild = leftRotate(node->lchild);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 & key < node->rchild->data)
	{
		
	}
}

int heightOfBinaryTree(Nodeptr root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + max2(heightOfBinaryTree(root->lchild), heightOfBinaryTree(root->rchild));
}

int main()
{
	Nodeptr root = NULL;
	// root = insertAVLTree();
}