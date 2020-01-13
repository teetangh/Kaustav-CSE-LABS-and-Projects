#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min (int a , int b)
{
	return (a<b)?a:b;
}

int max (int a , int b)
{
	return (a>b)?a:b;
}
typedef struct node
{
	int data;
	struct node* next;
}*NODE;

NODE insertRear(NODE first, int ele)
{
	NODE n = (NODE)malloc(sizeof(struct node));
	n->data = ele;
	n->next = NULL;

	if(first == NULL)
		return n;

	else
	{
		NODE last = first;
		while(last -> next != NULL)
			last = last -> next;

		last -> next = n;
	}
	return first;

}
unsigned int GCDmiddleschool(unsigned int m , unsigned int n)
{
	NODE first = NULL;
	int mimimum= min(m,n);

	for(int i = 1; i<= mimimum; i++)
	{
		if(m%i == 0 && n%i==0)
			first = insertRear(first,i);
	}

	int gcd=INT_MIN;
	NODE temp = first;
	while(temp->next != NULL)
	{
		if(temp -> data > gcd)
			gcd = temp -> data;

		temp = temp -> next;
	}

	if(temp -> data > gcd)
			gcd = temp -> data;

	return gcd;
}


void main()
{
	int m,n;
	printf("Enter 2 numbers for GCD\n");
	scanf("%d%d",&m,&n);

	printf("GCD is %d \n",GCDmiddleschool(m,n));
}

