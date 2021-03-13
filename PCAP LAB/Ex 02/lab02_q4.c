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
        MPI_Send(&a, 1, MPI_INT, 1, size, MPI_COMM_WORLD);

        MPI_Recv(&a, 1, MPI_INT, size - 1, size, MPI_COMM_WORLD, &status);
        a = a + 1;
        fprintf(stdout, "Rank %d process received: %d from process %d  \n", rank, a, size - 1);
        fflush(stdout);
    }
    else if (rank != size - 1)
    {
        MPI_Recv(&b, 1, MPI_INT, rank - 1, size, MPI_COMM_WORLD, &status);

        fprintf(stdout, "Rank %d process received : %d from process %d \n", rank, b, rank - 1);
        fflush(stdout);

        b = b + 1;

        MPI_Send(&b, 1, MPI_INT, rank + 1, size, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&c, 1, MPI_INT, size - 2, size, MPI_COMM_WORLD, &status);
        fprintf(stdout, "Rank %d process received: %d from process %d \n", rank, c, rank - 1);
        MPI_Send(&c, 1, MPI_INT, 0, size, MPI_COMM_WORLD);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
