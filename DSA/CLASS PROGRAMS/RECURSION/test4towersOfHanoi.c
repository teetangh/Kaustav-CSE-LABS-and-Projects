#include <stdio.h>
// #include <stdlib.h>
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 0)
        return;
    if (num == 1)
    {
        printf("Move disk 1 from %c peg to %c peg \n", frompeg, topeg);
        return;
    }
    else
    {
        towers(num - 1, frompeg, auxpeg, topeg);
        printf("Move disk %d from %c peg to %c peg \n", num, frompeg, topeg);
        towers(num - 1, auxpeg, topeg, frompeg);
    }

    // printf(" %c %c %c ", frompeg, topeg, auxpeg);
}

void main()
{
    int num;
    printf("Enter no of Disks for Tower of Hanoi \n");
    scanf("%d", &num);


    printf("Sequence of moves for Tower of Hanoi \n");
    towers(num, 'S', 'D', 'A');
}