/*
 * Created on Wed Jun 03 2020
 *
 * Copyright (c) 2020 Kaustav Ghosh
 */

// MINOR BUGS
#include <stdio.h>
#include <stdlib.h>

void mySwapfunction(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int HoarePartition(int *A, int l, int r)
{
    int p = A[l];
    int i = l;
    int j = r + 1;

    while (i < j)
    {
        while (A[i] < p)
            i++;
        while (A[j] < p)
            j--;
    }
    mySwapfunction(&A[i], &A[j]);
    mySwapfunction(&A[l], &A[j]);
}

void QuickSortHelper(int *A, int l, int r)
{
    if (l < r)
    {
        int s = HoarePartition(A, l, r);
        QuickSortHelper(A, l, s - 1);
        QuickSortHelper(A, s + 1, r);
    }
}
void QuickSort(int *A, int n)
{
    int l = 0;
    int r = n - 1;
    QuickSortHelper(A, l, r);
}
int main()
{
    int n;
    int arr[100];

    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    QuickSort(arr, n);
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
}