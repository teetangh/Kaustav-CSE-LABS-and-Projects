#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *llink, *rlink;
} * NODE;

void createList(int val)
{
	NODE nd;
	if (head == NULL)
	{
		nd = (NODE)malloc(sizeof(struct node));
		nd->llink = nd->rlink = NULL;
		nd->val = val;
		head = nd;
	}
	else
		printf("List is already Created \n");
}
void insertIntoList(int before, int val)
{
	NODE nd, newnd;
	nd = head;
	while (nd != NULL && nd->val != before)
		nd = nd->rlink;
	if (nd != NULL)
	{
		newnd = (NODE)malloc(sizeof(struct node));
		newnd->llink = newnd->rlink = NULL;
		newnd->val = val;

		if (nd->llink != NULL)
		{
			nd->llink->rlink = new nd;
			newnd->llink = nd->llink;
			newnd->rlink = nd;
			nd->llink = newnd;
		}
		else
		{
			newnd->rlink = nd;
			nd->llink = newnd;
			head = newnd;
		}
	}
	else
		printf("Unable to insert, node  with %d value not found", val);
}

void deleteAll(int delVal)
{
	NODE nd, nxtNode;
	nd = head;

	while (nd != NULL)
	{
		if (nd->val)
	}
}
int main()
{
	NODE head = NULL;
}
