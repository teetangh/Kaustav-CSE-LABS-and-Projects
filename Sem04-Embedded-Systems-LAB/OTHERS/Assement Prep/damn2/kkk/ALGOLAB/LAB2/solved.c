#include <stdio.h>
#include <stdlib.h>

int euclidGCD(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void)
{
	int a, b;
	printf("Enter 2 numbers:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	int gcd = euclidGCD(a, b);
	printf("GCD = %d\n", gcd);
}

//complexity - O(log n)