
#include <stdio.h>
int opcount = 0;

void heapify(int h[], int n)
{
	++opcount;
	int i, k, v, heapify, j;
	for (i = n / 2; i >= 1; i--)
	{
		k = i;
		v = h[k];
		heapify = 0;
		while (heapify == 0 && 2 * k <= n)
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

int main(void)
{
	printf("How many elements? ");
	int n;
	scanf("%d", &n);
	int current_len = 0;
	int h[20];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
		current_len++;
		heapify(h, current_len);
	}

	for (int i = 1; i <= n; i++)
		printf("%d  ", h[i]);
	printf("\nopcount: %d\n ", opcount);
}
