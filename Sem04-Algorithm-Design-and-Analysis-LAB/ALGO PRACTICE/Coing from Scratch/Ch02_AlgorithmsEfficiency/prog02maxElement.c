#include <stdio.h>

int maxElement(int *arr, int n)
{
    int maxval;
    if (n == 0)
        return -1;
    else
    {
        maxval = arr[0];
        for (int i = 1; i < n - 1; i++)
            if (arr[i] > maxval)
                maxval = arr[i];
    }
    return maxval;
}

int main()
{
    int arr[1000];
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    int maxELement = maxElement(arr, n);

    printf("The max element was found at index %d\n", (maxELement + 1));
    printf("The max element is %d\n", arr[maxELement]);
}
// // Sample IO
// 5
// 3 4 2 3 4
// The max element was found at index 5
// The max element is 4