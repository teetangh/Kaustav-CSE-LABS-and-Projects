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

	while (path[i] != '\0')

	{

		if (path[i] == 'L' || path[i] == 'l')

		{

			prev = t;

			t = t->lchild;

			if (t == NULL && path[i + 1] != '\0')

			{

				printf("\n****INVALID PATH****\n");

				free(n);

				return root;
			}
		}

		else

		{

			prev = t;

			t = t->rchild;

			if (t == NULL && path[i + 1] != '\0')

			{

				printf("\n****INVALID PATH****\n");

				free(n);

				return root;
			}
		}

		i = i + 1;
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

void postorder(struct node *root)

{

	if (root == NULL)

		return;

	postorder(root->lchild);

	postorder(root->rchild);

	printf("%d ", root->data);
}

void inorder(struct node *root)

{

	if (root == NULL)

		return;

	inorder(root->lchild);

	printf("%d ", root->data);

	inorder(root->rchild);
}

void preorder(struct node *root)

{

	if (root == NULL)

		return;

	printf("%d ", root->data);

	preorder(root->lchild);

	preorder(root->rchild);
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

	printf("DISPLAYING IN POST ORDER: ");

	postorder(root);

	printf("\n");

	printf("DISPLAYING IN IN ORDER: ");

	inorder(root);

	printf("\n");

	printf("DISPLAYING IN PRE ORDER: ");

	preorder(root);

	printf("\n");
}