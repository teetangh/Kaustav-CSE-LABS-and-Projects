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
NODE createBinarySearchTree(NODE root, int ele)
{
	NODE new_node;
	new_node = (NODE)malloc(sizeof(struct node));
	new_node->data = ele;

	if (root == NULL)
		return new_node;

	NODE curr = root;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		if (ele < curr->data)
		{
			if (curr->lchild == NULL)
			{
				printf("inserted %d as left child of %d\n", ele, curr->data);
				curr->lchild = new_node;
				return root;
			}
			curr = curr->lchild;
		}
		else if (ele > curr->data)
		{
			if (curr->rchild == NULL)
			{
				printf("inserted %d as right child child of %d\n", ele, curr->data);
				curr->rchild = new_node;
				return root;
			}
			curr = curr->rchild;
		}
	}
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

	printf("Enter 0.createBinaryTree(Recursive) \n");
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
			root = recursiveCreateBinaryTree();
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

		printf("Enter your choice\n");
		scanf(" %d", &choice);
	}
}
