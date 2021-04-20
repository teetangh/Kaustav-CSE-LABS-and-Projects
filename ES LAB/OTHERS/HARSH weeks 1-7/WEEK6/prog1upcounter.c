#include <LPC17xx.h>

unsigned int c = 0;
int main()
{
    unsigned int i = 0;
    unsigned int c = 0;

    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO->FIODIR |= 0x00000FF0;

    while (1)
    {
        c++;
        LPC_GPIO0->FIOPIN = c << 4;
        if (c = 0xFF)
            c = 0;
        for (i = 0; i < 20000; i++)
            ;
    }
}
