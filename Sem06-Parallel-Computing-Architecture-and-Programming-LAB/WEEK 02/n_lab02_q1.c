#include "mpi.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int rank, size, wordlength;
    MPI_Status status;
    char word[1000];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf(" Please enter a word to send ");
    scanf(" %s", word);
    wordlength = strlen(word);
    fflush(stdout);

    if (rank == 0)
    {

        MPI_Ssend(word, wordlength, MPI_CHAR, 1, 2, MPI_COMM_WORLD);

        MPI_Recv(word, wordlength, MPI_CHAR, 1, 3, MPI_COMM_WORLD, &status);
        printf(" %s\n", word);
        fflush(stdout);
    }
    else
    {
        MPI_Recv(word, wordlength, MPI_CHAR, 0, 2, MPI_COMM_WORLD, &status);
        for (int i = 0; i < wordlength; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
                word[i] = word[i] - 32;
            else if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] = word[i] + 32;
        }
        MPI_Ssend(word, wordlength, MPI_CHAR, 0, 3, MPI_COMM_WORLD);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
