#include <LPC17xx.h>

unsigned int c = 1;
int main()
{
    unsigned int j;
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;

    while (1)
    {
        LPC_GPIO0->FIOPIN = c << 4;
        c <<= 1;
        if (c = 0x00000100)
            c = 1;
        for (j = 0; j < 60000; j++)
            ;
    }
}