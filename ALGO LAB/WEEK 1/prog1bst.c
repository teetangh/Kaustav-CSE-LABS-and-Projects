#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
} * NODE;

NODE createBinaryTree(NODE root)
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	printf("Enter the value of the node. \n Enter -1 for returning. \n");
	scanf(" %d", &temp->data);
	if (temp->data == -1)
		return NULL;
	else
	{
		printf("For left Node of %d \n", temp->data);
		temp->lchild = createBinaryTree(temp->lchild);
		printf("For right Node of %d \n", temp->data);
		temp->rchild = createBinaryTree(temp->rchild);
	}
	return temp;
}
NODE createBinarySearchTree(NODE root, int ele)
{
	NODE new_node;
	new_node = (NODE)malloc(sizeof(struct node));
	new_node->data = ele;
	new_node->lchild = new_node = NULL;

	if (root == NULL)
		return new_node;

	NODE parent = NULL;
	NODE curr = root;

	while (curr != NULL)
	{
		parent = curr;
		if (curr->data < ele)
			curr = curr->rchild;
		else
			curr = curr->lchild;
	}

	if (ele < parent->data)
		parent->lchild = new_node;
	else
		parent->rchild = new_node;

	return root;
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

void main()
{
	NODE root = NULL;

	printf("Enter 0.createBinaryTree \n");
	printf("Enter 1.createBinarySearchTree \n");
	printf("Enter 2.displayTree \n");
	printf("Enter 3.searchTree \n");

	int choice;
	printf("Enter your choice\n");
	scanf(" %d", &choice);

	int tempvalue;

	while (1)
	{
		switch (choice)
		{
		case 0:
			root = createBinaryTree(root);
			break;

		case 1:
			printf("Enter Root Node\n");
			scanf(" %d", &tempvalue);
			while (tempvalue != -1)
			{
				root = createBinarySearchTree(root, tempvalue);
				break;
				printf("Enter Next Node.\n Enter -1 to exit\n");
				scanf(" %d", &tempvalue);
			}
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
