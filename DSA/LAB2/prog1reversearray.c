#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int i, n, A[10];

    printf("Please enter the size of your array \n");
    scanf("%d", &n);

    printf("Please enter your array \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n / 2; i++)
    {
        swap(&A[i], &A[n - i - 1]);
    }

    printf("Displaying your array \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
}