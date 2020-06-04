#include <stdio.h>

int ary[10][10], completed[10], n, cost = 0;

int smallest(int c)
{
	int i, nc = 1000;
	int min = 1000, kmin;

	for (i = 0; i < n; i++)
	{
		if ((ary[c][i] != 0) && (completed[i] == 0))
			if (ary[c][i] + ary[i][c] < min)
			{
				min = ary[i][0] + ary[c][i];
				kmin = ary[c][i];
				nc = i;
			}
	}

	if (min != 1000)
		cost += kmin;

	return nc;
}

void mincost(int city)
{
	int i, ncity;

	completed[city] = 1;

	printf("%d--->", city + 1);
	ncity = smallest(city);

	if (ncity == 1000)
	{
		ncity = 0;
		printf("%d", ncity + 1);
		cost += ary[city][ncity];
		return;
	}

	mincost(ncity);
}

int main()
{
	printf("Number of cities: ");
	scanf("%d", &n);

	printf("\nCost Matrix\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
		completed[i] = 0;
	}

	mincost(0);
	printf("\n\nMinimum cost is %d\n ", cost);

	return 0;
}