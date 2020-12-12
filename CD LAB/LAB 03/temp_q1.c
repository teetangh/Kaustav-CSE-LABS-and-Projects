#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int index = 0;
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

struct token *getNextToken(FILE *fp, int *ca)
{
	memset(buffer, 0, sizeof(buffer));
	index = 0;

	struct token *retToken;

	while (true)
	{
		ca = fgetc(fp);
		

		return retToken;
	}
}

int main(int argc, char const *argv[])
{
	char buffer[10];
	static int ca, cb;

	FILE *fp = fopen("sampleInputFile.c", "r");
	if (fp == NULL)
	{
		printf("Cannot Open File \n Exiting... \n");
		exit(0);
	}

	while (ca != NULL)
	{
		struct token *tkn = getNextToken(fp, &ca);
		printf("< %d,%d,%s,%s >", tkn->row, tkn->col, tkn->lexeme, tkn->type);
	}

	return 0;
}
