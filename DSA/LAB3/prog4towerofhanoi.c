//Towers of Hanoi
#include <stdio.h>
#include <stdlib.h>

void towers(int n, char fp, char tp, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", fp, tp);
        return;
    }

    else
    {
        towers(n - 1, fp, aux, tp);
        printf("\n move disk %d from peg %c to peg %c", n, fp, tp);
        towers(n - 1, fp, aux, tp);
    }
}

void main()
{
    int n;
    printf("Input the limit of terms \n");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
}