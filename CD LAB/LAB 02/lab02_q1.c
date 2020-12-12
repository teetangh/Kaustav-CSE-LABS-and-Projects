//Program to remove single and multiline comments from a given ‘C’ file.
#include <stdio.h>
int main()
{
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("lab02_q1_input.c", "r");
	if (fa == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	fb = fopen("lab02_q1_output.c", "w");

	int space = ' ';
	int newline = '\n';

	ca = getc(fa);

	while (ca != EOF)
	{
		if (ca == ' ')
		{
			putc(ca, fb);
			while (ca == ' ')
				ca = getc(fa);
		}

		if (ca == '\t')
		{
			putc(space, fb);
			while (ca == ' ' || ca == '\t')
				ca = getc(fa);
		}

		if (ca == '/')
		{
			cb = getc(fa);
			if (cb == '/')
			{
				while (ca != '\n')
					ca = getc(fa);
				putc(newline, fb);
			}
			else if (cb == '*')
			{
				do
				{
					while (ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
			}
			else
			{
				putc(ca, fb);
				putc(cb, fb);
			}
		}
		else
			putc(ca, fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}
