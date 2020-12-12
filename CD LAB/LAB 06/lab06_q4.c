#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[100];

// --------------------------------------------------
void S();
void L();
void Lprime();
// --------------------------------------------------

void invalid()
{
	printf("-----------------ERROR!----------------\n");
	exit(0);
}
void valid()
{
	printf("----------------SUCCESS!---------------\n");
	exit(0);
}

// --------------------------------------------------

void S()
{
	if (str[curr] == '(')
	{
		curr++;
		L();
		if (str[curr] == ')')
		{
			curr++;
			return;
		}
		else
			invalid();
	}
	else if (str[curr] == 'a')
	{
		curr++;
		return;
	}
	else
		invalid();
}

void L()
{
	S();
	Lprime();
}
void Lprime()
{
	if (str[curr] == ',')
	{
		curr++;
		S();
		Lprime();
	}
}

int main(int argc, char const *argv[])
{
	printf("Enter the string \n");
	scanf(" %s", str);

	S();
	if (str[curr] == '$')
		valid();
	else
	{
		printf("%c\n", str[curr]);
		invalid();
	}

	return 0;
}