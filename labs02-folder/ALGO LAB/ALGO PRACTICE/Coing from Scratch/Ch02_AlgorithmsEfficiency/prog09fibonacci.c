#include <stdio.h>

int fibonacci(int num)
{
    if (num == 0 || num == 1)
        return num;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int n;
    scanf(" %d", &n);
    int nthFibonacci = fibonacci(n);
    printf("The %d th fibonacci number is: %d", n, nthFibonacci);
}
// // Sample IO
// 8
// The 8 th fibonacci number is: 21
// 10
// The 10 th fibonacci number is: 55