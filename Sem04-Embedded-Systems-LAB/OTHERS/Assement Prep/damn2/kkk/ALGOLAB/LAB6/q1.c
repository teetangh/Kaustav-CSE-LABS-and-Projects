#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *llink, *rlink;
} t;
int c = 0;
int opcount = 0;
void insert(t **root, int x)
{
	t *temp;
	temp = (t *)malloc(sizeof(struct node));
	temp->data = x;
	temp->llink = temp->rlink = NULL;

	if (*root == NULL)
	{
		*root = temp;
	}
	else
	{
		t *curr, *prev;
		curr = *root;
		prev = NULL;

		while (curr != NULL)
		{
			prev = curr;
			if (x > curr->data)
			{
				curr = curr->rlink;
			}
			else
			{
				curr = curr->llink;
			}
		}
		if (x > prev->data)
		{
			prev->rlink = temp;
		}
		else
		{
			prev->llink = temp;
		}
	}
}
void inorder(t *root)
{
	opcount++;
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->llink);
		c++;
		inorder(root->rlink);
	}
}

void main()
{
	t *root;
	root = NULL;
	int n;
	printf("Enter nodes or -1 to exit: ");
	int i, x;
	while (true)
	{
		scanf("%d", &x);
		if (x == -1)
			break;
		insert(&root, x);
	}
	inorder(root);
	printf("No. of nodes : %d", c);
	printf("\nopcount:%d\n", opcount);
}