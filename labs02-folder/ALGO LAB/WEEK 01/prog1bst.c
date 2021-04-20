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
	NODE new_node = (NODE)malloc(sizeof(struct node));
	new_node->data = ele;
	new_node->lchild = new_node->rchild = NULL;

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

NODE searchBST(int item, NODE root)
{
	if (root == NULL)
		return root;
	if (item == root->data)
		return root;
	if (item < root->data)
		return searchBST(item, root->lchild);
	else
		return searchBST(item, root->rchild);
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

	int tempvalue, item;

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
			printf("Please enter the item to find in the BST \n");
			scanf(" %d", &item);
			NODE temp = searchBST(item, root);
			if (temp != NULL)
				printf("Item Found \n");
			else
				printf("Item NOT Found \n");
		default:
			exit(0);
			break;
		}

		printf("Enter your choice\n");
		scanf(" %d", &choice);
	}
}
