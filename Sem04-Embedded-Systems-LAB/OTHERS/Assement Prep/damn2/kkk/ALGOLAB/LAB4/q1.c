//Assignment Problem BruteForce
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int minVal = 1000;
int *minarray;
int **jobMatrix;
int opcount = 0;
void assignment(int *array, int n)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val += jobMatrix[i][array[i]];
	}

	if (val < minVal)
	{
		minVal = val;
		for (int k = 0; k < n; k++)
		{
			minarray[k] = array[k];
		}
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(int *a, int l, int n)
{
	int i;
	if (l == n - 1)
	{
		//after each permutation, call the assignment function
		//printf("%d ", a[i]);
		opcount++;
		assignment(a, n);
	}
	else
	{
		for (i = l; i < n; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, n);
			swap((a + l), (a + i)); // backtrack
		}
	}
}

int main()
{
	int *array;
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);

	jobMatrix = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		jobMatrix[i] = (int *)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &jobMatrix[i][j]);
	}
	printf("\n");
	array = (int *)calloc(n, sizeof(int));
	minarray = (int *)calloc(n, sizeof(int));

	//array with values 0,1,2.. to permute. Index represents person number and value at that index would represent job number assigned to that index aka person
	for (int i = 0; i < n; i++)
	{
		array[i] = i;
	}

	//send array to permute
	permute(array, 0, n);

	printf("Minimum Value is = %d using the following assignment\n", minVal);
	printf("<");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", minarray[i]);
	}
	printf(">\n");
	printf("operation count = %d\n", opcount);
}