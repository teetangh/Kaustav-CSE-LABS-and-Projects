#include <stdio.h>

int sequentialSearch2(int *arr, int n, int k)
{
    arr[n] = 1;
    int i = 0;
    while (arr[i] != k)
        i++;

    if (i < n)
        return i;
    else
        return -1;
}

int main()
{
    printf("Enter the number of array elements \n");
    int n;
    scanf(" %d", &n);

    int arr[100];
    printf("Enter the array elements \n");
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    printf(" Enter the key to be found\n");
    int k;
    scanf(" %d", &k);

    int foundORnotfound = sequentialSearch2(arr, n, k);
    if (foundORnotfound == -1)
        printf("Element couldnt be found\n");
    else
        printf("Element found at index %d\n", foundORnotfound + 1);
}
// // Sampel IO
// Enter the number of array elements
// 5
// Enter the array elements
// 1 2 3 4 5
//  Enter the key to be found
// 3
// Element found at index 3