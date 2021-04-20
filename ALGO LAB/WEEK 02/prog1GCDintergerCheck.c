#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
unsigned int integerCheckGCD(unsigned int m, unsigned int n)
{
	printf("%d+%d = (%d) \n", m, n, (m + n));
	int minimum = min(m, n);
	int t = minimum;

	int maximum = max(m, n);

	int remainder;
	int opcount = 0;
	while (t > 1)
	{
		opcount++;
		if (maximum % t == 0)
		{
			if (minimum % t == 0)
			{
				printf("opcount = %d \n", opcount);
				return t;
			}
		}

		t--;
	}

	printf("opcount = %d \n", opcount);
	return t;
}
void main()
{
	// unsigned int m,n;
	// scanf("%d%d",&m,&n);

	int prev = 1;
	int curr = 1;
	int next = 0;

	while (next < 1000)
	{
		next = curr + prev;
		prev = curr;
		curr = next;
		printf("GCD is %d \n", integerCheckGCD(prev, curr));
	}
}