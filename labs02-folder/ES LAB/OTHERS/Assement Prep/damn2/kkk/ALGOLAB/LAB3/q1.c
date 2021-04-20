#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, unsigned int n)
{
	unsigned int i, j;
	int temp;
	int opcount = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			++opcount;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("\nOperation Count %d\n", opcount);
}

int main()
{
	int *a;
	int i, n = 5;
	for (int j = 0; j < 4; j++)
	{
		a = (int *)malloc(sizeof(int) * n);
		for (int k = 0; k < n; k++)
			a[k] = n - k;
		printf("Initial array: ");
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		bubbleSort(a, n);
		printf("Elements after Bubble Sort: ");
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
		printf("\n");
		free(a);
		n = n + 5;
	}
	return 0;
}

//time complexity ø(n^2)