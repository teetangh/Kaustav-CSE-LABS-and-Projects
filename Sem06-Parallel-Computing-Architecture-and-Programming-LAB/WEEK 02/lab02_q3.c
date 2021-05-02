#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    int rank, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        int *arr = (int *)calloc(size, sizeof(int));
        printf(" Enter %d number of values in the aray ", size - 1);
        for (int i = 1; i < size; i++)
            scanf(" %d", &arr[i]);

        for (int i = 1; i < size; i++)
            MPI_Send(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&x, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);

        if (rank % 2 == 0)
            fprintf(stdout, "Even Rank %d process received: %d. After Squaring even ranked process : %d  \n", rank, x, x * x);
        else
            fprintf(stdout, "Odd Rank %d process received: %d. After Cubing odd ranked process : %d  \n", rank, x, x * x * x);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
