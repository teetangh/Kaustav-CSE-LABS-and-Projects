#include <stdio.h>
#include <stdlib.h>

int middleSchoolGCD(int a, int b)
{
	int temp;
	if (a < b)
		temp = a;
	else
		temp = b;
	int z = temp;
	int gcd = 1;
	for (int fact = 2; fact <= z; fact++)
	{
		while (((a % fact) == 0) && ((b % fact) == 0))
		{
			gcd = gcd * fact;
			a = a / fact;
			b = b / fact;
			if (a == 0 || b == 0)
				return gcd;
		}
	}
	return gcd;
}

int main(void)
{
	int a, b;
	printf("Enter 2 numbers:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	int gcd = middleSchoolGCD(a, b);
	printf("GCD = %d\n", gcd);
}