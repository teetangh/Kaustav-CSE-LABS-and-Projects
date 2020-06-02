#include <stdio.h>

int SUM(int array[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = sum + array[i];
    }
    printf("The sum using function is %d \n", sum);
}

void main()
{
    int n;
    int A[20];
    int sum = 0;
    int i;

    printf("Please enter the number of elements in the array \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Please enter Element no. %d ", i);
        scanf("%d", &A[i]);
        sum = sum + A[i];
    }

    printf("The sum is %d \n", sum);

    SUM(A, n);
}