#include <stdio.h>

unsigned int numberOfBinaryDigits(int num)
{
    unsigned int count = 1;
    while (num > 1)
    {
        count++;
        num = num / 2;
    }
    return count;
}

int main()
{
    int num;
    scanf(" %d", &num);
    unsigned int count = numberOfBinaryDigits(num);
    printf("The number of Binary Digits in the given number are: %d", count);
}
// // Sample IO
// 15
// The number of Binary Digits in the given number are: 4