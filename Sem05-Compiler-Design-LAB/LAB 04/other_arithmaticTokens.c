#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct token
{
	char token_name[100];
	int index;
	int row, col;
	char type[100];
} token;

void print_token(struct token s)
{
	printf("< %s %d %d>", s.token_name, s.row, s.col);
	return;
}

bool isRealNumber(char *str)
{
	int p = strlen(str);
	bool hasDecimal = false;
	for (int i = 0; i < p; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return hasDecimal;
}

bool isInteger(char *str)
{
	int i, len = strlen(str);
	if (len == 0)
		return false;
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || str[i] == '.' || (str[i] == '-' && i > 0))
			return false;
	}
	return true;
}

int isOperator(char ch)
{

	if (ch == '+' || ch == '/' || ch == '%' || ch == '-' || ch == '*' || ch == '^')
	{
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	FILE *fa = fopen(argv[1], "r");

	char word[20], num[20];
	int row = 1, col = 1;
	char c = getc(fa);

	struct token s;
	int i = 0;
	while (c != EOF)
	{
		//check for new line
		if (c == '\n')
		{
			row++;
			col = 1;
			printf("\n");
		}
		//any type of number
		else if (c == isdigit(c))
		{
			num[i++] = c;
			while (isdigit(c) || c == '.')
			{
				num[i++] = c;
				c = getc(fa);
				col++;
			}
			num[i] = '\0';
			if (isRealNumber(num) || isInteger(num))
			{
				strcpy(s.token_name, "Number");
				s.row = row;
				s.col = col - (int)(strlen(num) + 1);
				print_token(s);
			}
			i = 0;
			num[0] = '\0';
			continue;
		}
		else if (isOperator(c))
		{
			s.token_name[0] = c;
			s.token_name[1] = '\0';
			s.row = row;
			s.col = col - 1;
			print_token(s);
		}
		col++;
		c = getc(fa);
	}
	fclose(fa);
	return 0;
}