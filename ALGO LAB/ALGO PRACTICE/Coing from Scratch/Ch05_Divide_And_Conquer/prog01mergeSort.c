/*
 * Created on Wed Jun 03 2020
 *
 * Copyright (c) 2020 Kaustav Ghosh
 */
#include <stdio.h>
#include <stdlib.h>

int *MergeSort(int *A, int n)
{
    if (n <= 1)
        return A;
    else
    {
        int *B = (int *)calloc(n / 2, sizeof(int));
        int *C = (int *)calloc(n / 2, sizeof(int));
        for (int i = 0; i < n / 2; i++)
            B[i] = A[i];
        for (int i = n / 2; i < n; i++)
            C[i] = A[i];

        MergeSort(B, n / 2);
        MergeSort(C, n / 2);
        Merge(B, n / 2, C, n / 2, A);
    }
}
void Merge(int *B, int p, int *C, int q, int *A)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < p && j < q)
    {
        if (B[i] <= C[j])
            A[k++] = B[i++];
        else
            A[k++] = C[j++];
    }
    while (i < p)
        A[k++] = C[j++];
    while (j < q)
        A[k++] = B[i++];
}
int main()
{
    int n;
    int arr[100];

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    MergeSort(arr, n);
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}