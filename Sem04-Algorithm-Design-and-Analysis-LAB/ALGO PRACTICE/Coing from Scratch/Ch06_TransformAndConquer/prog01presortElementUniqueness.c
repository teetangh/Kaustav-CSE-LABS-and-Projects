#include <stdio.h>
#include <stdbool.h>

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
}
bool presortElementUniqueness(int *arr, int n)
{
    insertionSort(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[1000];
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    bool uniqueness = presortElementUniqueness(arr, n);
    if (uniqueness)
        printf("True\n");
    else
        printf("False\n");
}

// // Sample IO
// 10
// 1 2 3 4 5 6 7 8 9 1
// False