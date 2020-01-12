#include <stdio.h>
#include <stdlib.h>

void merge(int input[], int lb, int ub, int size)
{
    int i = lb;
    int k = 0;
    int mid = (lb + ub) / 2;
    int j = mid + 1;

    int *arr = (int *)malloc(size * sizeof(int));

    while (i <= mid && j <= ub)
    {
        if (input[i] <= input[j])
            arr[k++] = input[i++];
        else
            arr[k++] = input[j++];
    }
    while (i <= mid)
        arr[k++] = input[i++];
    while (j <= ub)
        arr[k++] = input[j++];

    for (k = 0; k < size; k++)
        input[k] = arr[k];
}
void mergeSort(int input[], int size)
{
    int lb = 0;
    int ub = size - 1;
    int mid;
    if (size == 0)
    {
        return;
    }
    else if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(input, mid - lb + 1);
        mergeSort(input + mid + 1, ub - mid);
        merge(input, lb, ub, size);
    }
    else
    {
        return;
    }
}
int main()
{
    int input[1000], length;
    scanf(" %d", &length);

    for (int i = 0; i < length; i++)
        scanf(" %d", &input[i]);

    mergeSort(input, length);
    for (int i = 0; i < length; i++)
        printf(" %d", input[i]);
}
