#include <LPC17xx.h>

unsigned int c = 1;
int main()
{
    unsigned int j = 0;
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO2->FIODIR |= 0xFFFFFEFF;

    while (1)
    {
        LPC_GPIO0->FIOPIN = c << 4;
        if (LPC_GPIO2->FIOPIN & 1 << 12)
            continue;
        else
            c <<= 1;
        if (c == 0x100)
            c = 1;
        for (j = 0; j < 10000; j++)
            ;
    }
}