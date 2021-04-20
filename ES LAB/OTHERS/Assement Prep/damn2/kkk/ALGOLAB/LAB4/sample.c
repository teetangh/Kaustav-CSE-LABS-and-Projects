//Knapsack BruteForce
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int knapsack(int *w, int *v, int n, int B)
{
	int i, temp;
	int maxVal = 0, maxSequence = 0, opcount = 0, index = 0;
	int totalWeight, totalValue;

	for (i = 1; i < pow(2, n); i++)
	{
		++opcount;
		temp = i;
		totalValue = totalWeight = 0;
		index = 0;
		while (temp)
		{
			if (temp & 0x1)
			{
				totalWeight += w[index];
				totalValue += v[index];
			}
			index++;
			temp = temp >> 1;
		}
		if (totalWeight <= B && totalValue > maxVal)
		{
			maxVal = totalValue;
			maxSequence = i;
		}
	}
	printf("\nOperation Count = %d\n", opcount);
	return maxSequence;
}

int main()
{
	unsigned int *v, *w, i, n, knaps, B;
	printf("Enter number of elements ");
	scanf("%d", &n);
	v = (int *)calloc(n, sizeof(int));
	w = (int *)calloc(n, sizeof(int));
	printf("Please enter Weights ");
	for (i = 0; i < n; i++)
		scanf("%d", &w[i]);
	printf("Please enter values ");
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("Please enter the Knapsack capacity");
	scanf("%d", &B);
	knaps = knapsack(w, v, n, B);
	printf("Knapsack contains the following items\n");
	i = 0;
	while (knaps)
	{
		if (knaps & 0x1)
			printf("Item %i   value %i\n", (i + 1), v[i]);
		i++;
		knaps = knaps >> 1;
	}
	return 0;
}