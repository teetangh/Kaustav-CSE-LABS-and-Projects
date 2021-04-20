#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2)
{
	int smaller = (num1 > num2)?num2:num1;
	int larger = (num1 >num2)?num1:num2;

	int temp;

	while(smaller >0)
	{
		temp = smaller;
		smaller = larger%smaller;
		larger = temp;
	}

	return larger;
}

int main(){
	printf("Enter two numbers\n");
	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);

	int GCD = gcd(n1,n2);
	printf("GCD: %d\n", GCD);
}