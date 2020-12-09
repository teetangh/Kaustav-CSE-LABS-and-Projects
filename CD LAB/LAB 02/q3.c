//Program to remove single and multiline comments from a given ‘C’ file.
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
int main()
{
	// File Handling  operations
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("input.c", "r");
	if (fa == NULL)
	{
		printf("Cannot open file \n");
		exit(0); 
	}
	fb = fopen("tempoutput1.c", "w");

	// For the keywords
	char buffer[100];	
	char keywords_table[32][10] = {
		"auto" , "break" , "case" , "char" ,"const" ,"continue" ,"default" ,"do",
		"double" ,"else" ,"enum" ,"extern" ,"float" ,"for" ,"goto" ,"if" ,"int" ,"long" ,"register",
 		"return" ,"short" ,"signed" ,"sizeof" ,"static" ,"struct" ,
 		"switch" ,"typedef" ,"union" ,"unsigned" ,"void" ,"volatile" ,"while" };

	// Counters
	int index = 0;
	int row_no = 1;
	// int column_no = 1;


	// Actual Scanning
	ca = getc(fa);
	while (ca != EOF)
	{
		// Single Line Comments
		if(ca==' ')
		{
			putc(ca,fb);
			while(ca==' ')
				ca = getc(fa);
		}
		// Multiline Comments
		if (ca=='/')
		{
			cb = getc(fa);
			if (cb == '/')
			{
				while(ca != '\n')
					ca = getc(fa);
			}
			else if (cb == '*')
			{
				do
				{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
			}
			else
			{
				putc(ca,fb);
				putc(cb,fb);
			}
		}
		else 
			putc(ca,fb);

		// Scanning for keywords
		buffer[index++] = ca;
		if(ca == '\n')
		{
			row_no++;

			for (int i = 0; i < 32; ++i)
			{
				if(strstr(buffer,keywords_table[i])!= NULL)
				{
					printf("%s row number:  %d  column nuber: %d  location : %s \n",keywords_table[i], row_no , index , strstr(buffer,keywords_table[i]));
					// puts(keywords_table[i]); 
				}

			}
			memset(buffer,0,sizeof(buffer));
			// buffer[0] = 0;
			index = 0;
		}

		// Getting the next chracter from the file descriptor
		ca = getc(fa);
	}

	// Closing the file descriptors
	fclose(fa);
	fclose(fb);

	return 0;
}
