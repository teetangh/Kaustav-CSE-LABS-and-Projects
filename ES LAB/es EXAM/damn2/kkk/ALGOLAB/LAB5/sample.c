//Insertion Sort
//Thetha(n^2)

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n)
{
	int i, j, v;
	int opcount = 0;
	for (i = 1; i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while (++opcount && j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = v;
	}
	printf("\n opcount = %d\n", opcount);
}

int main()
{
	int A[] = {5, 4, 3, 2, 1};
	int n = 5;
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	insertionSort(A, n);
	printf("Sorted Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}