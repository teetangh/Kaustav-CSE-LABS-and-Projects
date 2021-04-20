#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 9999

int myMin2(int num1, int num2)
{
    if (num1 <= num2)
        return num1;
    else
        return num2;
}

int mySquareFunction(int n)
{
    return n * n;
}

double BruteForceClosestPair(int **coordinateArray, int n)
{
    double d = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double distanceBtwnPoints = mySquareFunction(coordinateArray[i][0] - coordinateArray[j][0]) + mySquareFunction(coordinateArray[i][1] - coordinateArray[j][1]);
            d = sqrt(myMin2(d * d, distanceBtwnPoints));
        }
    }
    return d;
}

int main()
{
    // int coordinateArray[100][2];
    int n;
    do
    {
        printf("Number of points?\n");
        scanf(" %d", &n);
    } while (n < 2);

    int **coordinateArray = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        coordinateArray[i] = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter x and y coords of pint %d \n", (i + 1));
        scanf(" %d %d", &coordinateArray[i][0], &coordinateArray[i][1]);
    }

    double d = BruteForceClosestPair(coordinateArray, n);
    printf(" %lf", d);
}
// 5
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10