#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a[10];
	int top;
}Stack ;

void push(Stack* s, int x)
{
	if(s->top==9)
	printf("Stack Overflow\n");
	else
	{
		s->top+=1;
		s->a[s->top]=x;
	}
}