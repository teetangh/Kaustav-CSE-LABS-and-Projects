#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf(" %d", &n);

	int *arr = (int *)calloc(n, sizeof(int));

	for (int i = 0; i < n; ++i)
		scanf(" %d", &arr[i]);

	int *set1 = (int *)calloc(n, sizeof(int));
	int *set2 = (int *)calloc(n, sizeof(int));
}
