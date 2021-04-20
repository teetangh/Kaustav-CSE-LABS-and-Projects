#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size;

    char str[] = "HeLLO";

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (str[rank] >= 'a' && str[rank] <= 'z')
        str[rank] = str[rank] - 32;
    else if (str[rank] >= 'A' && str[rank] <= 'Z')
        str[rank] = str[rank] + 32;

    printf("My rank is %d and the modified string is %s \n", rank, str);

    MPI_Finalize();
    return 0;
}
