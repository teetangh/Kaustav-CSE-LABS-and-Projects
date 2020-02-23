#include <stdio.h>
#include <stdlib.h>
// #include "Solution.h"

int partition(int *arr, int start, int end)
{
    int pivot = start;
    int temp;
    int temp2;

    while (start < end)
    {
        while (arr[start] <= arr[pivot])
            start++;
        while (arr[end] > arr[pivot])
            end--;

        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp2 = arr[pivot];
    arr[pivot] = arr[end];
    arr[end] = temp2;
    return end;
}

void quickSort(int input[], int size)
{
    int lb = 0;
    int ub = size - 1;
    int loc;
    if (lb < ub)
    {
        loc = partition(input, lb, ub);
        quickSort(input, loc);
        quickSort(input + loc + 1, ub - loc);
    }
    else
        return;
}

int main()
{
    int n;
    scanf(" %d", &n);

    int *input = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf(" %d", &input[i]);

    quickSort(input, n);

    for (int i = 0; i < n; i++)
        printf(" %d", input[i]);

    free(input);
}
