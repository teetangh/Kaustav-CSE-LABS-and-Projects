	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>

int main()
{
	printf("Enter Super String \n");
	char string1[500];
	scanf(" %[^\n]s",string1);
	printf(" %s \n",string1);
	int stringlength1 = strlen(string1);
	printf("%d \n",stringlength1);

	printf("Enter Sub String \n");
	char string2[500];
	scanf(" %[^\n]s",string2);
	printf(" %s \n",string2);
	int stringlength2 = strlen(string2);
	printf("%d \n",stringlength2);

	int i,j;

	time_t t1  = clock();

	for(i = 0 ; i < stringlength1 ; i++ )
	{
		int isSubstring = 1;
		int tempI = i;  
		for( j = 0 ; j < stringlength2;)
		{
			if(string1[tempI++] != string2[j++])
			{
					// printf("is not Substring in this iteration \n");
				isSubstring = 0;
				break;
			}

			if(string1[tempI] == '\0' && string2[j] != '\0')
			{
					// printf("string 1 ended. Moving to next Iteratiuon\n");
			}
		}

		if (isSubstring == 1)
		{
			printf("Substring Foung at index %d \n", i);
				//Optional BREAK
			break; 

		}
		else
		{
				// printf("moving to next iteration of i\n");
			continue;
		}

	}	
	time_t t2 = clock();
	printf("\n Time Taken %ld milliseconds \n",(t2-t1));
}