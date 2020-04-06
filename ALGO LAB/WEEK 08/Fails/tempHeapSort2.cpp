#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void maxHeapify(int *arr, int n, int i)
{
    int largest = i;
    int l = (2 * i);
    int r = (2 * i) + 1;
    if (l <= n && arr[l] > arr[largest])
        largest = l;
    if (r <= n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
        maxHeapify(arr, n, i);
    for (int i = n; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);
        maxHeapify(arr, n, 1);
    }
}
int main()
{
    int n;
    printf("\nEnter size of array\n");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    printf("\nPlease enter array elements\n");
    for (int i = 1; i <= n; i++)
        scanf(" %d", &arr[i]);
    printf("Enter Your choice\n");
    printf("1.maxHeapify\n");
    printf("2.heapSort\n");
    printf("3.Display Heap\n");
    int choice;
    scanf(" %d", &choice);
    while (1)
    {
        switch (choice)
        {
        case 1:
            for (int i = n / 2; i >= 1; i--)
                maxHeapify(arr, n, i);
            break;
        case 2:
            heapSort(arr, n);
            break;
        case 3:
            printf("\nThe Heap elements are\n");
            for (int i = 1; i <= n; i++)
                printf(" %d", arr[i]);
            break;
        default:
            exit(0);
        }
        printf("\nEnter Your choice\n");
        scanf(" %d", &choice);
    }
}
