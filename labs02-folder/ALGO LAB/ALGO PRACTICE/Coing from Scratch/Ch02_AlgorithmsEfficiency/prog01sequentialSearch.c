#include <stdio.h>

int sequentialSearch(int *arr, int n, int k)
{
    int i = 0;
    while (i < n && arr[i] != k)
        i++;

    if (i < n)
        return i;
    else
        return -1;
}

int main()
{
    int arr[1000];
    int n, k;
    scanf(" %d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    int foundORnotFound = sequentialSearch(arr, n, k);

    if (foundORnotFound == -1)
        printf("The element could not be found");
    else
        printf("The element was found at index %d", (foundORnotFound + 1));
}

// // Sample IO
// 5 6
// 1 2 3 4 6
// The element was found at index 5