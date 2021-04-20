/*
 * Created on Tue Jun 02 2020
 *
 * Copyright (c) 2020 Kaustav Ghosh
 */

#include <stdio.h>

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

int main()
{
    int n;
    int arr[100];

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}
// // Sample IO
// 10
// 10 9 8 7 6 5 4 3 2 1
//  1 2 3 4 5 6 7 8 9 10