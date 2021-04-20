#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    // else if (wt[n - 1] > W) // could have but there would be a way to return a value otherwise
    else
        return knapsack(wt, val, W, n - 1);
}

int main(int argc, char const *argv[])
{
    printf("Please enter the number of items \n");
    int n;
    scanf(" %d", &n);

    printf("Please enter the weight array \n");
    int *wt = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf(" %d", &wt[i]);

    printf("Please enter the value array \n");
    int *val = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf(" %d", &val[i]);

    printf("Please enter the maximum weight of the bag \n");
    int W;
    scanf(" %d", &W);
    int profit = knapsack(wt, val, W, n);
    printf("The profit is %d", profit);
    return 0;
}
// // Sample IO
// Please enter the number of items
// 5
// Please enter the weight array
// 1 2 3 4 5
// Please enter the value array
// 5 4 3 2 1
// Please enter the maximum weight of the bag
// 10
// The profit is 14