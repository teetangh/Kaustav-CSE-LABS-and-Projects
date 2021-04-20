#include <stdio.h>

int EuclidGCD(int num1, int num2)
{
    int remainder = 1;
    printf("Inside the GCD functions: num1 is %d  and num2 is %d\num2", num1, num2);
    while (num2 != 0)
    {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;
}

int main(void)
{
    int num1, num2;
    scanf(" %d %d", &num1, &num2);

    int myGCD = EuclidGCD(num1, num2);

    printf("The GCD of %d and %d is %d\n", num1, num2, myGCD);
}