#include "mpi.h"
#include <stdio.h>

int power(int base, int exponent)
{
    if (base == 0 || base == 1)
        return base;
    else if (exponent == 0)
        return 1;
    else if (exponent == 1)
        return base;
    else
        return base * power(base, exponent - 1);
}

int main(int argc, char const *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int x = 10;
    printf("x = %d => pow(x,%d) is %d \n", x, rank, power(x, rank));

    MPI_Finalize();
    return 0;
}
