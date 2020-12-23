// 2. Multi-threaded prgram which finds summation of non negative numbers
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *summation(void *a)
{
    int *arr = (int *)a;
    int n = arr[0];
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
        sum += arr[i];
    return ((void *)sum);
}
int main()
{
    int n;
    printf("Enter the number of numbers:\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    arr[0] = n;
    printf("Enter the number:\n");
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &arr[i]);
    int ans = 0;
    pthread_t thread;
    pthread_create(&thread, NULL, &summation, (void *)arr);
    pthread_join(thread, (void **)&ans);
    printf("summation is %d\n", ans);
    return 0;
}