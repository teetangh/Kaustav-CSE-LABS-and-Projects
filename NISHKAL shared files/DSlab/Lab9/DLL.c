#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}*NODE;

void display(NODE first)
{
	if(first==NULL)
	{
		printf("List empty.\n");
		return;
	}
	while(first->rlink!=NULL)
	{
		printf("%d", first->data);
		first = first->rlink;
	}
	printf("%d\n", first->data);
}

NODE insert_first(NODE first, int ele)
{
	NODE n = (NODE)malloc(sizeof(struct node));
	n->data = ele; n->llink = NULL;
	if(first==NULL)
	{
		n->rlink = NULL;
		return n;
	}
	n->rlink = first;
	first->llink = n;
	return n;
}

NODE insert_rear(NODE first, int ele)
{
	NODE n = (NODE)malloc(sizeof(struct node));
	n->data = ele; n->llink = n->rlink = NULL;
	if(first==NULL)
		return n;
	NODE cur = first;
	while(cur->rlink!=NULL)
		cur = cur->rlink;
	cur->rlink = n;
	n->llink = cur;
	return first;
}

NODE delete_rear(NODE first)
{
	if(first==NULL)
	{
		printf("List is empty.\n");
		return first;
	}
	NODE cur = first;
	while(cur->rlink!=NULL)
		cur = cur->rlink;
	cur->llink->rlink = NULL;
	printf("%d", cur->data);
	free(cur);
	return first;
}

NODE delete_front(NODE first)
{
	if(first==NULL)
	{
		printf("List is empty.\n");
		return first;
	}
	else if(first->rlink==NULL)
	{
		printf("%d", first->data);
		free(first);
		return first;
	}
	NODE cur = first;
	first = first->rlink;
	cur->llink->rlink = NULL;
	printf("%d", cur->data);
	free(cur);
	return first;
}

void main()
{
	NODE first = NULL;
	int ch, ele;
	printf("1.Insert from front 2.Insert from rear 3.Delete from front 4.Delete from rear 5.Display 6.Exit\n");
	while(1)
	{
		printf("Enter choice:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the element:\n");
					scanf("%d", &ele);
					first = insert_first(first, ele);
					break;
			case 2: printf("Enter the element:\n");
					scanf("%d", &ele);
					first = insert_rear(first, ele);
					break;
			case 3: delete_front(first);
					break;
			case 4: delete_rear(first);
					break;
			case 5: display(first);
					break;
			default: exit(0);
		}
	}
}