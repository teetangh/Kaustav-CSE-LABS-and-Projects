#include <LPC17xx.h>

unsigned int c = 0xFF;
int main()
{
    unsigned int j;
-    unsigned long LED = 0x00000000;
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_PINCON->PINSEL2 &= 0xFFFFFFF;
    LPC_GPIO2->FIODIR |= 0xFFFFFEFF;

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
        for (j = 0; j < 20000; j++)
            ;
    }
}