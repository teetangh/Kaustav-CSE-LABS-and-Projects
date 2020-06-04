#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int match(char text[], char pattern[])
{
	int i = 0, j = 0;
	for (i = 0; i < strlen(text) - strlen(pattern) + 1; i++)
	{
		for (j = 0; j < strlen(pattern); j++)
		{
			if (text[i + j] != pattern[j])
				break;
		}
		if (j == strlen(pattern))
			return i;
	}
	return -1;
}

int main()
{
	char text[256];
	char pattern[256];
	printf("Enter text: ");
	gets(text);
	printf("Enter pattern: ");
	gets(pattern);
	int index = match(text, pattern);
	if (index == -1)
		printf("Not Found\n");
	else
		printf("Found at %d\n", index + 1);
}

//complexity - ø(mn)