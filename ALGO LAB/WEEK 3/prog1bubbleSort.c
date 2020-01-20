#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	scanf(" %d",&n);

	int *arr = (int *)calloc(n,sizeof(int));

	for (int i = 0; i < n; ++i)
		scanf(" %d",&arr[i]);

	time_t t1 = clock();

	for(int i =0 ; i < n ;i++)
	{
		int isSorted = 1;
		// printf("Debug 1 \n");
		for(int j = 0 ; j < n - i - 1;j++)
		{
			// printf("Debug 2 \n");
			if(arr[j]>arr[j+1])
			{
				isSorted = 0;
				// printf("Debug 3 \n");
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}
		if(isSorted)
		{
			// printf("Debug 4 \n");
			break;
		}
	}

	time_t t2 = clock();

	printf("After Bubble sorting \n");
	for (int i = 0; i < n; ++i)
		printf(" %d ",arr[i]);


	printf("\n Time Taken %ld milliseconds \n",(t2-t1));
}