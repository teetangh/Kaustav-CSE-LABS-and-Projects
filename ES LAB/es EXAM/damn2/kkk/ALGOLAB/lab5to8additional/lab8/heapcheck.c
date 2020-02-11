#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum
{
	false,
	true
} bool;

// a binary rep is a heap if every parent is greater
// than it's children.

bool isHeap(int arr[], int i, int n)
{
	if (i >= (n - 2) / 2) //i.e. if i index is a leaf node
		return true;

	if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2] && isHeap(arr, 2 * i + 1, n) && isHeap(arr, 2 * i + 2, n))
		return true;

	return false;
}

int main()
{
	printf("Enter number of elements in heap: \n");
	int n;
	scanf("%d", &n);
	int arr[n];

	printf("Enter heap elements: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	isHeap(arr, 0, n) ? printf("HEAP!\n") : printf("NOT HEAP!\n");

	return 0;
}