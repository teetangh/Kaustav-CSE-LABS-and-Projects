#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"
int main()
{
    int n;
    stack s;
    s.top = -1;
    printf("\nInput the number of elements: ");
    scanf("%d", &n);
    int k;
    printf("\nInput the number of elements to delete: ");
    scanf("%d", &k);
    int c = 0;
    int i;
    printf("\nInput the elements: ");
    for (i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        push(&s, x);
    }
    for (i = 0; i < n; i++)
    {
        if (s.arr[i] < s.arr[i + 1])
        {
            int j;
            n--;
            for (j = 0; j < n; j++)
            {
                s.arr[j] = s.arr[j + 1];
            }
            i = -1;
            c++;
            if (c == k)
            {
                s.top = n - 1;
                display(&s);
                exit(0);
            }
        }
    }
    s.top = n - 1;
    display(&s);
    return 0;
}