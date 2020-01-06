#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 10

typedef struct node
{
	char *stu_name;
	int stu_id;
	float stu_average;
	struct node *next;
} * NODE;

typedef struct head
{
	int count;
	struct node *next;
} HEAD;

struct node *insert(HEAD *head, char *name, int ele, float average)
{
	NODE n = (NODE)malloc(sizeof(struct node));
	n->stu_name = name;
	n->stu_id = ele;
	n->stu_average = average;
	n->next = n;

	if (head->next == NULL)
	{
		(head->count)++;
		head->next = n;
		return head->next;
	}
	NODE last = head->next;

	while (last->next != last)
		last = last->next;

	last->next = n;
	n->next = head->next;
	(head->count)++;

	return head->next;
}

void display(HEAD *head)
{
	NODE dum = head->next;
	if (head->next == NULL)
	{
		printf("Empty List \n");
		return;
	}

	else
	{
		printf("( %s %d %f )\t", dum->stu_name, dum->stu_id, dum->stu_average);
		dum = dum->next;
		/* code */
		while (dum != head->next)
		{
			printf("( %s %d %f )\t", dum->stu_name, dum->stu_id, dum->stu_average);
			dum = dum->next;
		}
		// printf(" %s \n %d \n %f \n", dum->stu_name, dum->stu_id, dum->stu_average);
	}
}

struct node *remove_duplicates(HEAD *head)
{
	NODE temp = head->next;

	if (head->next == NULL || head->next->next == head->next)
		return head->next;

	NODE curr = head->next;

	NODE dup = NULL;

	while (curr->next != curr)
	{
		if (curr->stu_name == curr->next->stu_name)
		{
			dup = curr->next;
			curr->next = dup->next;
			free(dup);
		}
		else
			curr = curr->next;
	}

	return head->next;
}

struct node *sort(HEAD *head)
{
	HEAD *head2 = (HEAD *)malloc(sizeof(struct head));
	NODE temp = (NODE)head->next;
	NODE i = NULL, j = NULL;

	NODE min;

	if (head->next == NULL || head->next->next == head->next)
		return head->next;

	for (i = head->next; i->next != head->next; i = i->next)
	{
		min->stu_average = i->stu_average;
		for (j = i->next; j->next != head->next; j = j->next)
		{
			if (min->stu_average > j->stu_average)
				min->stu_average = j->stu_average;
		}

		head2->next = insert(head2, min->stu_name, min->stu_id, min->stu_average);
	}
	return head2->next;
}

void main()
{
	HEAD *head = (HEAD *)malloc(sizeof(struct head));
	head->count = 0;
	head->next = NULL;

	char *namet;
	int idt;
	float avgt;

	int ch;

	printf(" 1.Insert \n 2.Display \n 3.Remove Duplicates \n 4.Sort \n 5.exit \n");

	do
	{
		printf("\n ================== \n ");
		printf("\n Enter choice \n");
		scanf(" %d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter Details name id average \n");
			fflush(stdin);

			gets(namet);
			scanf("%d", &idt);
			scanf("%f", &avgt);

			printf(" %s\n", namet);
			printf(" %d\n", idt);
			printf(" %f\n", avgt);
			head->next = insert(head, namet, idt, avgt);
			break;
		case 2:
			display(head);
			break;
		case 3:
			head->next = remove_duplicates(head);
			break;
		case 4:
			head->next = sort(head);
			break;
		default:
			break;
		}

		fflush(stdin);
	} while (ch <= 4);
}