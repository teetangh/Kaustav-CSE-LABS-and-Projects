#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a[10];
	int top;
}Stack ;


void display(Stack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
	printf("%d ",s->a[i]);
	printf("\n");
}