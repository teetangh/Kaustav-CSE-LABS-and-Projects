#include <stdio.h>

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}

void main()
{
    int n;
    printf("enter the n \n ");
    scanf(" %d", &n);
    for (int i = 0; i <= n; i++)
    {
        /* code */
        printf(" %d ", fib(i));
    }

    printf("\n fib(n) %d \n", fib(n));
}