#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int main()
{
	printf("Enter String 1\n");
	char string1[500];
	scanf(" %[^\n]s",string1);
	printf(" %s \n",string1);

	printf("Enter String 2\n");
	char string2[500];
	scanf(" %[^\n]s",string2);
	printf(" %s \n",string2);

	int i = 0;
	int isEqual = 1;
	int opcount = 0;

	while(string1[i] != '\0' && string2[i] != '\0')
	{
		printf("inside Loop %d \n",opcount++);
		opcount++;
		if(string1[i] != string2[i])
		{
			printf("Not isEqual\n");
			isEqual = 0;
			break; 
		}
		i++;

		if(string1[i] == '\0' && string2[i] !='\0')
		{
			isEqual = 0;
			printf("String 2 islonger \n");
		}

		if(string1[i] != '\0' && string2[i] =='\0')
		{
			isEqual = 0;
			printf("String 1 islonger \n");
		}
	}

	printf("opcount is %d \n",opcount);
	if(isEqual)
		printf("isEqual\n");
	else
		printf("not isEqual\n");


}