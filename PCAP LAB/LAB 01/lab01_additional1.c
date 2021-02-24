#include "mpi.h"
#include <stdio.h>
#include <stdbool.h>

int reverse_digits(int num)
{
    int rev = 0;

    while (num > 0)
    {
        int last = num % 10;
        rev = rev * 10 + last;
        num = num / 10;
    }

    return rev;
}

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int input[] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};

    switch (rank)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        printf("after reversing %d , we get %d (Rank %d) \n", input[rank], reverse_digits(input[rank]), rank);
        break;

    default:
        break;
    }

    MPI_Finalize();
    return 0;
}
