#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    int rank, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter a value in the master process (rank %d) ", rank);
        scanf(" %d", &a);
        for (int i = 1; i < size; i++)
            MPI_Send(&a, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&b, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        fprintf(stdout, "Rank %d process received: %d \n", rank, b);
    }

    MPI_Finalize();
    return 0;
}
