#include <stdio.h>

void result(int A[], int n)
{
    int i;
    int big;
    int big2;

    big = A[0];

    for (i = 0; i < n; i++)
    {
        if (A[i] > big)
        {
            big = A[i];
        }
    }

    big2 = A[0];

    for (i = 0; i < n; i++)
    {
        if (A[i] > big2 && A[i] < big)
        {
            big2 = A[i];
        }
    }

    printf("The biggest element is %d ", big);
    printf("The 2nd biggest element is %d ", big2);
}

void main()
{
    int n;
    int A[10];
    int i;

    printf("Please enter the number of elements in the array");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Please enter the disctinct Element no. %d ", i);
        scanf("%d", &A[i]);
    }

    result(A, n);
}