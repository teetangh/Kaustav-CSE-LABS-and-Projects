#include <stdio.h>
#include <stdlib.h>

//static int count = 0;

void NoOfOccurences(int *arr, int n, int key,int *p)
{
    int a =0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            a++;
        }
    }

    *p=a;

    printf("No of occurences of %d in the array using function is %d \n", key, *p);
    return;
}

void main()
{
    int n, key;
    int *p;

    printf("Enter no of elements for the array \n");
    scanf("%d", &n);

    int *ptr = (int *)calloc(n, sizeof(int));
    printf("Enter elements in the array \n");

    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d", &ptr[i]);
    }

    printf("Enter key to find the no of occurences ");
    scanf("%d", &key);

    NoOfOccurences(ptr, n, key,p);

    printf("No of occurences of %d in the array using Main is %d \n", key, *p);
}