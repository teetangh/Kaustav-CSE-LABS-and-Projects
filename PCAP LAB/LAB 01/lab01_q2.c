#include "mpi.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank % 2 == 0)
        printf("Hello (Rank %d) \n", rank);
    else
        printf("World (Rank %d) \n", rank);

    MPI_Finalize();
    return 0;
}
