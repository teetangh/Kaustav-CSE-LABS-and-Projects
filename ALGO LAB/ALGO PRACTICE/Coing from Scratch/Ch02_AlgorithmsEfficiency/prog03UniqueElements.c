#include <stdio.h>
#include <stdbool.h>

bool uniqueElements(int *arr, int n)
{
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (arr[i] == arr[j])
                return false;

    return true;
}

int main()
{
    int arr[1000];
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    bool uniqueness = uniqueElements(arr, n);
    if (uniqueness)
        printf("True\n");
    else
        printf("False\n");
}

// // Sample IO
// 10
// 1 2 3 4 5 6 7 8 9 1
// False