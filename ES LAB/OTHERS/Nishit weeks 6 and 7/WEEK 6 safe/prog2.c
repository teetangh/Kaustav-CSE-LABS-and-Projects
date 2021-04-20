#include <LPC17xx.h>

unsigned int c = 0;
int main()
{
    unsigned int i;
    unsigned long LED = 0x00000000;
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    while (1)
    {
        c++;
        LPC_GPIO->FIOPIN = c << 4;
        if (c = 0xFF)
            c = 0;
        for (i = 0; i < 30000; i++)
            ;
    }
}