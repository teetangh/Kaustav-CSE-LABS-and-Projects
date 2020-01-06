#include <stdio.h>
#include <stdlib.h>

void main()
{
    enum day
    {
        mon,
        tue,
        wed=20
    };

    enum day d1, d2;
    d1 = wed;
    printf(" %d ", d1);
}