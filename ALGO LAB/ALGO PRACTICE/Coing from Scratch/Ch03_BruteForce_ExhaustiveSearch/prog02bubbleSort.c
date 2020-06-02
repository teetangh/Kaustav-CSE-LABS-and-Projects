#include <stdio.h>
#include <stdbool.h>
void swapByAddress(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSortOptimized(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapByAddress(&arr[j], &arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted == true)
            break;
        else
            continue;
    }
    printf("After Optimized Bubble Sorting\n");
}
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
                swapByAddress(&arr[j + 1], &arr[j]);
        }
    }
    printf("After Bubble Sorting\n");
}

int main()
{
    int n;
    int arr[100];

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    // bubbleSort(arr, n);
    bubbleSortOptimized(arr, n);
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}
// 5
// 3 2 4 1 5
// After Optimized Bubble Sorting
//  1 2 3 4 5