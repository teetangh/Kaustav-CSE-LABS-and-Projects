#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coeff;
	int expon;
	struct node *next;
} NODE;

NODE *insert_order(NODE *L1, int c, int e)
{
	NODE *n = (NODE *)malloc(sizeof(struct node));
	n->coeff = c;
	n->expon = e;
	n->next = NULL;

	if (L1 == NULL)
		return n;

	else if (e <= L1->expon)
	{
		n->next = L1;
		return n;
	}

	NODE *prev, *curr = L1;

	while (curr != NULL && curr->expon < e)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = n;
	n->next = curr;
	return L1;
}

void display(NODE *first)
{
	if (first == NULL)
	{
		// printf(" DEBUG 1 \n");
		printf("The list is empty.\n");
		return;
	}

	while (first != NULL)
	{
		// printf(" DEBUG 2 \n");
		printf("%dx%d", first->coeff, first->expon);
		if (first->next != NULL)
		{
			// printf(" DEBUG 3 \n");
			printf(" + ");
		}
		first = first->next;
		// printf(" DEBUG 4 \n");
	}
}

NODE *add_poly(NODE *L1, NODE *L2)
{
	int c, sum;
	NODE *L3;

	while (L1 != NULL && L2 != NULL)
	{
		if (L1->expon == L2->expon)
			c = 0;
		else if (L1->expon < L2->expon)
			c = -1;
		else
			c = 1;

		switch (c)
		{
		case 0:
			sum = L1->coeff + L2->coeff;
			if (sum != 0)
				L3 = insert_order(L3, sum, L1->expon);
			L1 = L1->next;
			L2 = L2->next;
			break;

		case -1:
			L3 = insert_order(L3, L1->coeff, L1->expon);
			L1 = L1->next;
			break;

		case 1:
			L3 = insert_order(L3, L1->coeff, L2->expon);
			L2 = L2->next;
			break;
		}
	}

	while (L1 != NULL)
	{
		L3 = insert_order(L3, L1->coeff, L1->expon);
		L1 = L1->next;
	}

	while (L2 != NULL)
	{
		L3 = insert_order(L3, L2->coeff, L2->expon);
		L2 = L2->next;
	}

	return L3;
}

void main()
{
	NODE *L1 = NULL;
	NODE *L2 = NULL;
	NODE *L4 = NULL;

	int c1, e1, c2, e2;

	int choice;
	printf("Enter \n 1.Insert order in L1 \n 2.Insert order in L2 \n 3.Add the polynomials 4.display \n");
	do
	{
		printf("\nEnter your choice\n");
		scanf(" %d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter coeff and expon to insert in L1 \n");
			scanf("%d", &c1);
			scanf("%d", &e1);
			L1 = insert_order(L1, c1, e1);
			break;
		case 2:
			printf("Enter coeff and expon to insert in L2 \n");
			scanf("%d", &c2);
			scanf("%d", &e2);
			L2 = insert_order(L2, c2, e2);
			break;
		case 3:
			L4 = add_poly(L1, L2);
			break;
		case 4:
			display(L4);
			break;
		}

	} while (choice < 5);
}