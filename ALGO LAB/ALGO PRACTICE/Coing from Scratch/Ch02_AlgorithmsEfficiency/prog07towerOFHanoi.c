#include <stdio.h>

void TowerOfHanoiFunction(char frompeg, char topeg, char auxpeg, int num)
{
    if (num <= 0)
        printf("No disks to transfer. Stop playing pranks \n");
    else if (num == 1)
        printf("Move disk 1 from %c to %c \n", frompeg, topeg);
    else
    {
        TowerOfHanoiFunction(frompeg, auxpeg, topeg, num - 1);
        printf("Move disk %d from %c to %c \n", num, frompeg, topeg);
        TowerOfHanoiFunction(auxpeg, topeg, frompeg, num - 1);
    }
    return;
}

int main()
{
    int numOfDisks;
    printf("Please enter the number of Disks \n");
    scanf(" %d", &numOfDisks);

    TowerOfHanoiFunction('A', 'C', 'B', numOfDisks);
}
// // Sample IO
// Please enter the number of Disks
// 4
// Move disk 1 from A to B
// Move disk 2 from A to C
// Move disk 1 from B to C
// Move disk 3 from A to B
// Move disk 1 from C to A
// Move disk 2 from C to B
// Move disk 1 from A to B
// Move disk 4 from A to C
// Move disk 1 from B to C
// Move disk 2 from B to A
// Move disk 1 from C to A
// Move disk 3 from B to C
// Move disk 1 from A to B
// Move disk 2 from A to C
// Move disk 1 from B to C