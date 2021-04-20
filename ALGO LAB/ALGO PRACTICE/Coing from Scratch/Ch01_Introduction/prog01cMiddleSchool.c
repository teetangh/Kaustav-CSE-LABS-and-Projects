#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number)
{
    unsigned int count = 0;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return true;
    }
    return false;
}

int middleSchoolGCD(int num1, int num2)
{
    int commonFactorArray[1000];

    int j = 0;
    // Can't initialise identifiers of different types in C
    for (int i = 0; (i <= num1 && i <= num2); i++)
    {
        if (isPrime(i) && ((num1 % i) == 0) && (num2 % i) == 0)
            commonFactorArray[j++] = i;
    }
    return commonFactorArray[--j];
}

int main(void)
{
    int num1, num2, r;
    scanf(" %d %d", &num1, &num2);

    int myGCD = middleSchoolGCD(num1, num2);

    printf("The GCD of %d and %d is %d\n", num1, num2, myGCD);
}