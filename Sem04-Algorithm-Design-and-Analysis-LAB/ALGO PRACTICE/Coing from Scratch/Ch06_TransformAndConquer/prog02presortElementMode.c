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
int presortElementMode(int *arr, int n)
{
    insertionSort(arr, n);
    int i = 0;
    int modeFrequency = 0;
    int modevalue = arr[0];
    while (i <= n - 1)
    {
        int runlength = 1;
        int runvalue = arr[i];

        while (i + runlength <= n - 1 && arr[i + runlength] == runvalue)
            runlength++;
        if (runlength > modeFrequency)
        {
            modeFrequency = runlength;
            modevalue = runvalue;
        }
        i = i + runlength;
    }
    return modevalue;
}

int main()
{
    int arr[1000];
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    int modevalue = presortElementMode(arr, n);
    printf("The mode element in the array is %d", modevalue);
}

// // Sample IO
// 10
// 1 2 3 4 5 6 7 8 9 1
// False