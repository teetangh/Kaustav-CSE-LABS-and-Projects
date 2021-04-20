#include <stdio.h>
#include <string.h>

void intAppend(int *arr1, int key, int *n)
{
    int arr2[1] = {key};
    memcpy(arr1 + sizeof(arr1), arr2, 1 * sizeof(int));
    (*n)++;
}

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int i;

    // memcpy(a + 5, b, 5 * sizeof(int));
    // for (i = 0; i < 10; i++)
    // {
    //     printf("%d\n", a[i]);
    // }

    int size = 10;
    intAppend(a, 99, &size);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
}