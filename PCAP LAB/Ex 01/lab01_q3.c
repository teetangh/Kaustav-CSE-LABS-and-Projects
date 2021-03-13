#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;

    const int num1 = 10;
    const int num2 = 20;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int result = 0;
    switch (rank)
    {
    case 0:
        result = num1 + num2;
        printf("%d + %d is %d (Rank %d) \n", num1, num2, (num1 + num2), rank);
        break;
    case 1:
        result = num1 - num2;
        printf("%d - %d is %d (Rank %d) \n", num1, num2, (num1 - num2), rank);
        break;
    case 2:
        result = num1 * num2;
        printf("%d * %d is %d (Rank %d) \n", num1, num2, (num1 * num2), rank);
        break;
    case 3:
        result = num1 / num2;
        printf("%d / %d is %d (Rank %d) \n", num1, num2, (num1 / num2), rank);
        break;
    }

    MPI_Finalize();
    return 0;
}
