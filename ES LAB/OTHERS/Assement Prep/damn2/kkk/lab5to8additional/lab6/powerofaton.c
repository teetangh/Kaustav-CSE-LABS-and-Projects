#include<stdio.h> 

/* Function to calculate x raised to the power y */
int power(int x, unsigned int y) 
{ 
	if (y == 0) 
		return 1; 
	else if (y%2 == 0) 
		return power(x, y/2)*power(x, y/2); 
	else
		return x*power(x, y/2)*power(x, y/2); 
} 

/* Program to test function power */
int main() 
{ 
	int a; 
	unsigned int n = 3;

	printf("Enter base (a): \n");
	scanf("%d", &a);
	printf("Enter exponent (n): \n");
	scanf("%d", &n);

	printf(" %d^%d = %d\n", a, n, power(a, n)); 
	return 0; 
} 
