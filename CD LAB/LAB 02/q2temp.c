//Program to remove single and multiline comments from a given ‘C’ file.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fa, *fb;
	int ca, cb;
	///////////////////////////////////////Removinng Comments///////////////////

	// fa = fopen("input.c", "r");
	// if (fa == NULL)
	// {
	// 	printf("Cannot open file \n");
	// 	exit(0);
	// }
	// fb = fopen("tempoutput.c", "w");
	// ca = getc(fa);
	// while (ca != EOF)
	// {
	// 	if(ca==' ')
	// 	{
	// 		putc(ca,fb);
	// 		while(ca==' ')
	// 			ca = getc(fa);
	// 	}
	// 	if (ca=='/')
	// 	{
	// 		cb = getc(fa);
	// 		if (cb == '/')
	// 		{
	// 			while(ca != '\n')
	// 				ca = getc(fa);
	// 		}
	// 		else if (cb == '*')
	// 		{
	// 			do
	// 			{
	// 				while(ca != '*')
	// 					ca = getc(fa);
	// 				ca = getc(fa);
	// 			} while (ca != '/');
	// 		}
	// 		else
	// 		{
	// 			putc(ca,fb);
	// 			putc(cb,fb);
	// 		}
	// 	}
	// 	else putc(ca,fb);
	// 	ca = getc(fa);
	// }

	// fclose(fa);
	// fclose(fb);

	///////////////////////////////////////Removinng Preprocessor 1///////////////////

	fa = fopen("tempoutput.c", "r");
	if (fa == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	fb = fopen("output.c", "w");
	ca = getc(fa);
	while (ca != EOF)
	{
		if (ca=='#')
		{
			cb = getc(fa);
			if (cb == 'd' ||  cb == 'i' || cb == 'e' || cb == 'u' || cb == 'p' )
			{
				while(ca != '\n')
					ca = getc(fa);
				int new_line = '\n';
				putc(new_line,fb);
			}
			else
			{

				putc(ca,fb);
				putc(cb,fb);
			}

		}
		else
			putc(ca,fb);
		ca = getc(fa);
	}
	///////////////////////////////////////Removinng Preprocessor 2///////////////////

	// // For the keywords
	// char buffer[100];
	// char preprocessor_directives[10][10] = {"define", "include", "undef", "ifdef",
	// 										"ifndef", "if", "else", "elif", "else", "endif", "error", "pragma"};

	// // Prereqs
	// int space = ' ';
	// int new_line = '\n';

	// fa = fopen("tempoutput.c", "r");
	// if (fa == NULL)
	// {
	// 	printf("Cannot open file \n");
	// 	exit(0);
	// }
	// fb = fopen("output.c", "w");

	// // Counters
	// int index = 0;

	// ca = getc(fa);
	// while (ca != EOF)
	// {
	// 	// Single Line Comments
	// 	if (ca == ' ')
	// 	{
	// 		putc(ca, fb);
	// 		while (ca == ' ')
	// 			ca = getc(fa);
	// 	}
	// 	// Multiline Comments
	// 	if (ca == '/')
	// 	{
	// 		cb = getc(fa);
	// 		if (cb == '/')
	// 		{
	// 			while (ca != '\n')
	// 				ca = getc(fa);
	// 		}
	// 		else if (cb == '*')
	// 		{
	// 			do
	// 			{
	// 				while (ca != '*')
	// 					ca = getc(fa);
	// 				ca = getc(fa);
	// 			} while (ca != '/');
	// 		}
	// 		else
	// 		{
	// 			putc(ca, fb);
	// 			putc(cb, fb);
	// 		}
	// 	}
	// 	else if (ca == '\n')
	// 	{
	// 		memset(buffer, 0, sizeof(buffer));
	// 		index = 0;
	// 		putc(new_line, fb);

	// 		cb = getc(fa);
	// 		int cb2 = cb;
	// 		if (cb == '#')
	// 		{
	// 			while (cb != ' ' && cb != '\n' && cb != NULL)
	// 			{
	// 				cb = getc(fa);
	// 				buffer[index++] = cb;
	// 			}

	// 			bool contains_directive = false;
	// 			for (int i = 0; i < 10; ++i)
	// 			{
	// 				if (strstr(buffer, preprocessor_directives[i]) != NULL)
	// 				{
	// 					contains_directive = true;
	// 					break;
	// 				}
	// 			}

	// 			if (!contains_directive)
	// 			{
	// 				// puts(buffer,fb);
	// 				putc(cb2, fb);
	// 				for (int i = 0; i < strlen(buffer); ++i)
	// 					putc(buffer[i], fb);

	// 				memset(buffer, 0, sizeof(buffer));
	// 				index = 0;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		buffer[index++] = ca;
	// 		putc(ca, fb);
	// 	}
	// 	ca = getc(fa);
	// }

	fclose(fa);
	fclose(fb);
	return 0;
}
