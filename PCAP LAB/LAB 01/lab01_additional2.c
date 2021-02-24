#include "mpi.h"
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        for (int i = 1; i < 50; i++)
        {
            if (isPrime(i))
                printf("Prime number %d (Rank %d ) \n", i, rank);
        }
    }
    else
    {
        for (int i = 51; i < 101; i++)
        {
            if (isPrime(i))
                printf("Prime number %d (Rank %d ) \n", i, rank);
        }
    }

    MPI_Finalize();
    return 0;
}
