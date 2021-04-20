#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int m, int r)
{
	int i, j, k;
	int p = m - l + 1;
	int q = r - m;

	int B[p], C[q];

	for (i = 0; i < p; i++)
		B[i] = A[l + i];
	for (j = 0; j < q; j++)
		C[j] = A[m + 1 + j];

	i = j = 0;
	k = l;
	while (i < p && j < q)
	{
		if (B[i] <= C[j])
		{
			A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
		k++;
	}
	while (i < p)
	{
		A[k] = B[i];
		i++;
		k++;
	}
	while (j < q)
	{
		A[k] = C[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
}

int main(void)
{
	int A[] = {12, 14, 11, 13, 2, 6, 17};
	int n = 7;
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	mergeSort(A, 0, n - 1);
	printf("Sorted Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}