#include <stdio.h>

void swapByAddress(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swapByAddress(&arr[i], &arr[minIndex]);
    }
}

int main()
{
    int n;
    int arr[100];

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    selectionSort(arr, n);
    printf("After Sorting\n");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}
// // Sample IO
// 5
// 3 1 2 5 4
// After Sorting
//  1 2 3 4 5