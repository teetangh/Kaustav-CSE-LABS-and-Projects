#include "CharStack.h"

void main()
{
	int choice;
	stack s;
	s.top = -1;
	char item;

	printf("Enter 1 for Push\n");
	printf("Enter 2 for Pop\n");
	printf("Enter 3 for is Full and is Empty\n");
	printf("Enter 4 for Display\n");
	printf("Enter 5 for exit\n");

	do
	{
		printf("Enter your choice\n");

		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:

			printf("Please enter the character to push\t");
			scanf(" %c", &item);
			push(&s, item);
			break;
		case 2:
			pop(&s);
			break;
		case 3:
			isFull(&s);
			isEmpty(&s);
			break;
		case 4:
			display(&s);
			break;
		case 5:
			break;

		default:
			printf("\n Invalid Choice \n");
			break;
		}

	} while (choice != 5);
}