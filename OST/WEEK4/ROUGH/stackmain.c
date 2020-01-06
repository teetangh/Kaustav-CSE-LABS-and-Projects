#include <stdio.h>
#include <stdlib.h>
#include "stacklib.h"


int main()
{
	int n;int x,a;
	Stack *s;
	s->top=-1;
	printf("Enter 1 for push, 2 for pop, 3 for display and 4 to exit: ");
	scanf("%d",&n);
	while(n==1||n==2||n==3)
	{
		switch(n)
		{
			case 1:
			printf("Enter the element: ");
			scanf("%d",&x);
			push(s,x);
			break;

			case 2:
			a=pop(s);
			printf("Popped Element: %d\n",a);
			break;

			case 3:
			display(s);
			break;
		}
		printf("Enter your choice: ");
		scanf("%d",&n);
	}
}