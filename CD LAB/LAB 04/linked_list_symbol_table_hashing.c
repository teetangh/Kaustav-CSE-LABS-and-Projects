#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TableLength 30

enum tokenType
{
	EOFILE = -1,
	LESS_THAN,
	LESS_THAN_OR_EQUAL,
	GREATER_THAN,
	GREATER_THAN_OR_EQUAL,
	EQUAL,
	NOT_EQUAL
};

struct token
{
	char *lexeme;
	int index;
	unsigned int rowno, colno;
	enum tokenType type;
};

struct ListElement
{
	struct token tok;
	struct ListElement *next;
};

struct ListElement *TABLE[TableLength];

void Initialize()
{
	for (int i = 0; i < TableLength; ++i)
		TABLE[i] = NULL;
}

void Display()
{
}

void HASH(char *str)
{
}
