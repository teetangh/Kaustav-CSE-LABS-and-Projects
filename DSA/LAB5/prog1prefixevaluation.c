#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "IntStack.h"

char *strrev(char *str)
{
	char *p1, *p2;

	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

int eval(char, int, int);

void main()
{
	stack s1;
	s1.top = -1;

	char op1, op2;

	char prefix[20], symb;
	int i = 0;
	int result;
	printf("Enter the prefix expression \n");
	gets(prefix);
	strrev(prefix);

	while ((symb = prefix[i++]) != '\0')
	{
		if (isdigit(symb))
			push(&s1, symb - '0');
		else
		{
			op1 = pop(&s1);
			op2 = pop(&s1);
			result = eval(symb, op1, op2);
			push(&s1, result);
		}
	}

	printf("The result is %d\n", pop(&s1));
}

int eval(char opr, int n1, int n2)
{
	switch (opr)
	{
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		return n1 * n2;
		break;
	case '/':
		return n1 / n2;
		break;

	case '^':
	case '$':
		return pow(n1, n2);
		break;
	}
}