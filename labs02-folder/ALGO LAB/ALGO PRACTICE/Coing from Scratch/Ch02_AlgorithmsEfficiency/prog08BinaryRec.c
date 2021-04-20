#include <stdio.h>

int BinRec(int n)
{
    if (n == 1)
        return 1;
    else
        return BinRec(n / 2) + 1;
}

int main()
{
    int num;
    scanf(" %d", &num);
    int count = BinRec(num);
    printf("The number of Binary Digits in the given number are: %d", count);
}
// // Sample IO
// 15
// The number of Binary Digits in the given number are: 4