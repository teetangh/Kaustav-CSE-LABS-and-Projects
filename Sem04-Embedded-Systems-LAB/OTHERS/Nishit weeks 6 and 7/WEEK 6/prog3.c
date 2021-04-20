#include <LPC17xx.h>

unsigned int c = 0xFF;
int main()
{
    unsigned int i, j;
    unsigned long LED = 0x00000000;
    LPC_PINCON->PINSEL0 &= 0xFF00FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    while (1)
    {
        c--;
        LPC_GPIO0->FIOPIN = c << 4;
        if (c == -1)
            c = 0xFF;
        for (j = 0; j < 30000; j++)
            ;
    }
}