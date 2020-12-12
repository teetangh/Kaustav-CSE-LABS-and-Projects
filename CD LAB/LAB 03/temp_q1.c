#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct token
{
	char lexeme[100];
	int row,col;
	char token_type[100];
};


// void fillToken()

token getNextToken(FILE* fp)
{

	ca = fgetc(fp);
	while(ca != EOF)
	{
		int i = 0;
		buffer[0] = '\0';

		if(ca == '=')
		{
			buffer[i++] = ca;
			ca = fgetc(fp);

			if(ca == '=')
			{
					buffer[i++] = ca;
				buffer[i] = '\0';
				printf("\n Relational operator %s \n" , buffer);
			} 

			else
			{
				buffer[i] = '\0';
				printf("\n Assignment Operator %s \n" , buffer);
			}
		}
		else
		{
			if(ca == '<' || ca == '>' || ca == '!')
			{
				buffer[i++] = ca;
				ca = fgetc(fp);

				if(ca == '=')
					buffer[i++] = ca;

				buffer[i] = '\0';
				printf("\n Relational operator %s \n",buffer);
			}
			else
				buffer[i] = '\0';

		}

		ca = fgetc(fp);
	}	

	return 
}


int main(int argc, char const *argv[])
{
	char ca,buffer[10];
	FILE *fp = fopen("sampleInputFile.c","r");

	if(fp == NULL)
	{
		printf("cannot open File \n");
		exit(0);
	}

	while(getNextToken)
	{
		printf("%s\n", );
	}


}