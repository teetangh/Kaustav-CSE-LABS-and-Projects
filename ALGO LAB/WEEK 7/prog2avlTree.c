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
Nodeptr insertAVLTree(Nodeptr root)
{
	Nodeptr temp =
		if (root == NULL) return;
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
	root = recursiveCreateBianryTree();
}