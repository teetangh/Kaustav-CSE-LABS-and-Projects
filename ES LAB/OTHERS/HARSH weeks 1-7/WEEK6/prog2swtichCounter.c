#include <LPC17xx.h>

unsigned int c = 0xFF;

int main()
{
    int i = 0;
    LPC_PPINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_PINCON->PINSEL2 &= 0xFCFFFFFF;
    LPC_GPIO2->FIODIR |= 0xFFFFFFEF;

    while (1)
    {
        if (LPC_GPIO2->FIOPIN & 1 << 12)
            c--;
        else
            c++;
        if (c == -1)
            c = 0xFF;
        LPC_GPIO0->FIOPIN = c << 4;
        if (c == 0x100)
            c = 0;
        for (i = 1; i < 10000; i++)
            ;
    }
}