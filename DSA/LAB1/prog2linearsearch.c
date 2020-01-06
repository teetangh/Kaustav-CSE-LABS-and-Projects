//Working Linear Search

#include <stdio.h>

void Lsearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == array[i])
        {
            printf("Element %d found at position %d of the array", key, i);
        }
    }
}

void main()
{
    int n;
    int A[20];
    int key;
    int i;

    printf("Please enter the number of elements in the array");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Please enter Element no. %d ", i);
        scanf("%d", &A[i]);
    }

    printf("Please enter the element to be found in the array");
    scanf("%d", &key);

    Lsearch(A, n, key);
}