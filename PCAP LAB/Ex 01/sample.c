#include "mpi.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("My rank is %d in total %d process \n", rank, size);
    MPI_Finalize();
    return 0;
}
