#include <stdio.h>
#include <stdlib.h>

void maxtrixMultiplication(int **c, int **a, int **b, int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf(" The result of the matrix multiplication is: \n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            printf(" %d", c[i][j]);
}

int main()
{

    int r1, c1, r2, c2;

    int **a = (int **)malloc(r1 * sizeof(int *));
    int **b = (int **)malloc(r2 * sizeof(int *));
    do
    {
        printf("Enter no of rows and columns of matrix a ", &r1, &c1);
        scanf(" %d %d", &r1, &c1);
        for (int i = 0; i < r1; i++)
            a[i] = (int *)malloc(c1 * sizeof(int));

        printf("Enter no of rows and columns of matrix b ", &r2, &c2);
        scanf(" %d %d", &r2, &c2);
        for (int i = 0; i < r2; i++)
            b[i] = (int *)malloc(c2 * sizeof(int));

        printf("Enter the elements of the matrix a \n");
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                scanf(" %d", &a[i][j]);
        printf("Enter the elements of the matrix b \n");
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                scanf(" %d", &b[i][j]);
    } while (c1 != r2);

    int **c = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r2; i++)
        c[i] = (int *)malloc(c2 * sizeof(int));

    maxtrixMultiplication(c, a, b, r1, c1, r2, c2);
}

// // Sample IO
// Enter no of rows and columns of matrix a 2 2
// Enter no of rows and columns of matrix b 2 2
// Enter the elements of the matrix a
// 1 0
// 0 1
// Enter the elements of the matrix b
// 1 0
// 0 1
//  The res