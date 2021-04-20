#include <stdio.h>

int myMin2(int num1, int num2)
{
    if (num1 <= num2)
        return num1;
    else
        return num2;
}

int consecIntegerCheckGCD(int num1, int num2)
{
    int minimumOfNumbers = myMin2(num1, num2);
    int result1, result2;
    if ((result1 = num1 % minimumOfNumbers) == 0)
    {
        if ((result2 = num2 % minimumOfNumbers) == 0)
            return minimumOfNumbers;
    }
    else
        minimumOfNumbers--;
}

int main(void)
{
    int num1, num2;
    scanf(" %d %d", &num1, &num2);

    int myGCD = consecIntegerCheckGCD(num1, num2);

    printf("The GCD of %d and %d is %d \n", num1, num2, myGCD);
}
