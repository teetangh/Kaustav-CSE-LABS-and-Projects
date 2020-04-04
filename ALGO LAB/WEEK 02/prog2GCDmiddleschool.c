#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int isPrime(int number)
{
	int count = 0;
	for (int i = 2; i < number; ++i)
	{
		if (number % i == 0)
			count++;
	}
	if (count > 0)
		return 0;
	else
		return 1;
}
unsigned int GCDmiddleschool(unsigned int m, unsigned int n)
{
	int minimum = min(m, n);
	int answer = 1;
	for (int i = 1; i <= minimum; i++)
	{
		if (!isPrime(i))
			continue;
		else
		{
			if (m % i == 0 && n % i == 0)
			{
				printf("%d\n", i);
				answer = answer * i;
			}
		}
	}
	return answer;
}

void main()
{
	int m, n;
	printf("Enter 2 numbers for GCD\n");
	scanf("%d%d", &m, &n);

	printf("GCD is %d \n", GCDmiddleschool(m, n));
}
