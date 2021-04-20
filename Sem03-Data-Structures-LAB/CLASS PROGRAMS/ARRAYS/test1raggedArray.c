#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j;
    int **table;
    int rowNo, colNo;

    printf("Enter no of rows\n");
    scanf(" %d", &rowNo);

    table = (int **)calloc(1 + rowNo, sizeof(int *));

    for (i = 0; i < rowNo; i++)
    {
        /* code */
        printf("Enter no of coloumns for row %d \n", i + 1);
        scanf(" %d", &colNo);
        table[i] = (int *)calloc(1 + colNo, sizeof(int));
        printf("Enter elements for row %d \n", i + 1);

        for (j = 1; j <= colNo; j++)
        {
            scanf(" %d", &table[i][j]);
        }

        table[i][0] = colNo;
        printf("Size of row %d is %d \n", i + 1, table[i][0]);
    }

    table[i] = NULL;

    for (i = 0; i < rowNo; i++)
    {
        /* code */
        printf("\n Displaying %d row no elements \n ", i + 1);
        for (j = 1; j <= *table[i]; j++)
            printf(" %d ", table[i][j]);
        printf("\n");
    }
}