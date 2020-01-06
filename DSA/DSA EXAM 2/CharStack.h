#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define true 1
#define false 0

typedef struct 
{
	char arr[MAX];
	int top;
} stack ,STACK;

//Push Operation
void push(stack *ps, char item)
{

	if (ps->top == MAX - 1)
	{
		printf("stack Overflow\n");
		return;
	}
	else
	{
		ps->arr[++(ps->top)] = item;
		return;
	}
}

//Pop operation
char pop(stack *ps)
{
	char item;
	if (ps->top == -1)
	{
		printf("stack Underflow\n");
		return -1;
	}
	else
	{
		item = ps->arr[ps->top--];
		printf("Item popped is %c\n", item);
		return item;
	}
}

void display(stack *ps)
{
	printf("Elements in the stack are:\n");
	for (int i = ps->top; i >= 0; i--)
	{
		/* code */
		printf("%c\n", ps->arr[i]);
	}
}

void isFull(stack *ps)
{
	if (ps->top == MAX - 1)
	{
		printf("stack Overflow\n");
		return;
	}
}
void isEmpty(stack *ps)
{
	if (ps->top == -1)
	{
		printf("stack Empty\n");
		return;
	}
}

