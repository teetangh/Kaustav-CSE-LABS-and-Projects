#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *fa, *fb;

	fa = fopen("lab02_q2_input.c", "r");
	fb = fopen("lab02_q2_output.c", "w+");

	if (fa == NULL || fb == NULL)
	{
		printf("Cannot open the IO files \n ");
		exit(0);
	}

	// For the keywords
	char buffer[100];
	char preprocessor_directives[12][10] = {"define", "include", "undef", "ifdef",
											"ifndef", "if", "else", "elif", "else", "endif", "error", "pragma"};

	// Counters
	int index = 0;
	int space = ' ';
	int newline = '\n';
	int ca, cb;

	while ((ca = fgetc(fa)) != EOF)
	{
		if (ca == '\n')
		{

			while (ca == '\n')
			{
				memset(buffer, 0, sizeof(buffer));
				index = 0;
				fputc(newline, fb); // fputc(ca, fb);

				cb = fgetc(fa);
				if (cb == '#')
				{
					// while (cb != ' ' && cb != '\n')
					while (cb != '\n')
					{
						buffer[index++] = cb;
						cb = fgetc(fa);
					}
				}
				else
				{
					fputc(cb, fb);
					break;
				}
				bool contains_directive = false;

				// Searching for a matching Preprocessor directive
				for (int i = 0; i < sizeof(preprocessor_directives) / sizeof(preprocessor_directives[0]); i++)
				{
					if (strstr(buffer, preprocessor_directives[i]) != NULL)
					{
						contains_directive = true;
						break;
					}
				}

				if (!contains_directive)
				{
					for (int i = 0; i < strlen(buffer); i++)
						fputc(buffer[i], fb);

					memset(buffer, 0, sizeof(buffer));
					index = 0;
				}

				ca = '\n';
			}
		}
		else
		{
			buffer[index++] = ca;
			fputc(ca, fb);
		}
	}

	fclose(fa);
	fclose(fb);

	return 0;
}

////////////////////////////// ALTERNATE APPROACH/////////////////////////////////
// fa = fopen("tempoutput.c", "r");
// if (fa == NULL)
// {
// 	printf("Cannot open file \n");
// 	exit(0);
// }
// fb = fopen("output.c", "w+");
// ca = getc(fa);
// while (ca != EOF)
// {
// 	if (ca == '#')
// 	{
// 		cb = getc(fa);
// 		if (cb == 'd' || cb == 'i' || cb == 'e' || cb == 'u' || cb == 'p')
// 		{
// 			while (ca != '\n')
// 				ca = getc(fa);
// 			int new_line = '\n';
// 			putc(new_line, fb);
// 		}
// 		else
// 		{

// 			putc(ca, fb);
// 			putc(cb, fb);
// 		}
// 	}
// 	else
// 		putc(ca, fb);
// 	ca = getc(fa);
// }