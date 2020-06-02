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

NODE copy(NODE root)

{

	if (root == NULL)

		return NULL;

	NODE t = root;

	t->lchild = copy(root->lchild);

	t->rchild = copy(root->rchild);
}

int equalt(NODE root1, NODE root2)

{

	return ((!root1 && !root2) || (root1 && root2 && (root1->data == root2->data) && equalt(root1->lchild, root2->lchild) && equalt(root1->rchild, root2->rchild)));
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

		printf("\n1.INSERT\t2.CREATE COPY AND CHECK FOR EQUALITY\n");

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

			printf("\nCREATING COPY AND CHECKING FOR EQUALITY:\n");

			break;
		}

	} while (ch != 2);

	NODE cpy = copy(root);

	int m = equalt(root, cpy);

	if (m == 1)

		printf("\nEQUAL TREES\n");

	else

	{

		printf("\nUN-EQUAL TREES\n");
	}
}