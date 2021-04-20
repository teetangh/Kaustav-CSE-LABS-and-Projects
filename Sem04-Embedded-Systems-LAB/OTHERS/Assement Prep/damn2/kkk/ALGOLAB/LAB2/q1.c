#include <stdio.h>
#include <stdlib.h>

int consIntGCD(int a, int b)
{
	int temp;
	if (a < b)
		temp = a;
	else
		temp = b;
	while (temp != 1)
	{
		if (a % temp == 0 && b % temp == 0)
			return temp;
		temp -= 1;
	}
	return temp;
}

int main(void)
{
	int a, b;
	printf("Enter 2 numbers:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	int gcd = consIntGCD(a, b);
	printf("GCD = %d\n", gcd);
}