#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int row = 0;
int col = 0;
int ca = 0, cb = 0;

char buffer[100];
char keywords_table[32][10] = {
	"auto", "break", "case", "char", "const", "continue", "default", "do",
	"double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
	"return", "short", "signed", "sizeof", "static", "struct",
	"switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

struct token
{
	int row, col;
	char type[50];
	char lexeme[50];
};

struct token *fillToken(struct token *retToken, int row, int col, char *type, char *lexeme)
{
	retToken->row = row;
	retToken->col = col;
	strcpy(retToken->lexeme, lexeme);
	strcpy(retToken->type, type);
	return retToken;
}

struct token *getNextToken(FILE *fp)
{

	struct token *retToken = NULL;

	ca = fgetc(fp);
	col++;
	// while (ca != '\n' && ca != EOF)
	while (ca != EOF)
	{
		memset(buffer, 0, sizeof(buffer));
		int index = 0;
		do
		{
			if (ca == ' ')
				col++;
			if (ca == '\t')
				col = col + 4;

			ca = fgetc(fp);
		} while (ca == ' ' || ca == '\t');

		// if (isalpha(ca))
		// {
		// 	while (isalpha(ca))
		// 	{
		// 		ca = fgetc(fp);
		// 	}
		// }

		if (ca == '+')
		{
			buffer[index++] = ca;
			ca = fgetc(fp);
			col++;

			if (ca == '+')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "increment operator", "++");
				return retToken;
			}
			else if (ca == '=')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "assignment operator", "+=");
				return retToken;
			}
			else
			{
				fillToken(retToken, row, col, "arithmetic operator", "+");
				return retToken;
			}
		}
		else if (ca == '-')
		{
			buffer[index++] = ca;
			ca = fgetc(fp);
			col++;

			if (ca == '-')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "decrement operator", "--");
				return retToken;
			}
			else if (ca == '=')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "assignment operator", "-=");
				return retToken;
			}
			else
			{
				fillToken(retToken, row, col, "arithmetic operator", "-");
				return retToken;
			}
		}
		else if (ca == '*')
		{
			buffer[index++] = ca;
			ca = fgetc(fp);
			col++;

			if (ca == '*')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "exponentiation operator", "**");
				return retToken;
			}
			else if (ca == '=')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "assignment operator", "*=");
				return retToken;
			}
			else
			{
				fillToken(retToken, row, col, "arithmetic operator", "*");
				return retToken;
			}
		}

		else if (ca == '=')
		{
			buffer[index++] = ca;
			ca = fgetc(fp);
			col++;

			if (ca == '=')
			{
				col++;
				buffer[index++] = ca;
				buffer[index] = '\0';
				fillToken(retToken, row, col, "relational operator", "==");
				return retToken;
			}
			else
			{
				fillToken(retToken, row, col, "assignment operator", "=");
				return retToken;
			}
		}

		else if (ca == ';')
		{
			buffer[index++] = ca;
			fillToken(retToken, row, col, "semi-colon", ";");
			return retToken;
		}

		ca = fgetc(fp);
	}

	return retToken;
}

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("sampleInputFile.c", "r");
	if (fp == NULL)
	{
		printf("Cannot Open File \n Exiting... \n");
		exit(0);
	}

	while (ca != EOF)
	{
		struct token *tkn = getNextToken(fp);
		printf("< %d,%d,%s,%s >", tkn->row, tkn->col, tkn->lexeme, tkn->type);
	}

	return 0;
}
