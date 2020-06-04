#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high + 1;
    do
    {
        do
        {
            i++;
            opcount++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
            opcount++;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);

    } while (i <= j);
    swap(&arr[i], &arr[j]);
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void)
{
    int A[] = {12, 14, 11, 13, 17};
    int n = 5;
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    quickSort(A, 0, n - 1);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\nopcount = %d\n", opcount);
}