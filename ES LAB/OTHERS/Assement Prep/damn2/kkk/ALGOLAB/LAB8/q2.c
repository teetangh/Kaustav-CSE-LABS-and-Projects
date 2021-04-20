//bottom up heap construction - Sample program

#include <stdio.h>
int opcount = 0;

void heapify(int h[], int n)
{
	int i, k, v, heapify, j;
	for (i = n / 2; i >= 1; i--)
	{
		k = i;
		v = h[k];
		heapify = 0;
		while (++opcount && heapify == 0 && 2 * k <= n)
		{
			j = 2 * k;
			if (j < n)
				if (h[j] < h[j + 1])
					j += 1;
			if (v >= h[j])
				heapify = 1;
			else
			{
				h[k] = h[j];
				k = j;
			}
		}
		h[k] = v;
	}
	return;
}

void main()
{
	int n = 6;
	//elements are from index 1 to 6
	int h[7] = {0, 2, 9, 8, 6, 5, 7};
	for (int i = 1; i <= n; i++)
		printf("%d  ", h[i]);
	heapify(h, n);
	printf("\nHeap created is:\n");
	for (int i = 1; i <= n; i++)
		printf("%d  ", h[i]);

	//sorting the heap
	int index = n;
	for (int i = 0; i < n; i++)
	{
		int temp = h[index];
		h[index] = h[1];
		h[1] = temp;
		index--;
		heapify(h, index);
	}
	printf("\nHeap Sorted is:\n");
	for (int i = 1; i <= n; i++)
		printf("%d  ", h[i]);

	printf("\n%d\n ", opcount);
}