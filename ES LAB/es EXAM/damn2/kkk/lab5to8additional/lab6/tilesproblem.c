#include <stdio.h>
#include <stdlib.h>

int computeways(int n)
{
	//basically calculating nth FIBONACCI number.
	if(n<=2)
		return n;
	else
		return computeways(n-1) + computeways(n-2);
}

int main()
{
	int n, ways;

	printf("Enter length of 2 x n grid: \n");
	scanf("%d", &n);

	ways = computeways(n);

	printf("Number of ways of filling a 2 x %d grid is %d\n", n, ways);
}