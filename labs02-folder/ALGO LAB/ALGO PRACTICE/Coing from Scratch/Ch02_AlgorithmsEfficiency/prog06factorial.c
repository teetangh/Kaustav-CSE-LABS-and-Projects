#include <stdio.h>

int factorialFunction(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return factorialFunction(n - 1) * n;
}

int main()
{
    int n;
    scanf(" %d", &n);
    int factorialResult = factorialFunction(n);
    printf(" The factorial of the given number is : %d", factorialResult);
}
// // Sample IO
// 6
//  The factorial of the given number is : 720