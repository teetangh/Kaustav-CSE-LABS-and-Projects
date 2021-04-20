#include <LPC17xx.h>

unsigned int i, j;
unsigned long LED - 0x00000010;

int main()
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;

    while (1)
    {
        LED = 0x00000010;
        for (i = 1; i < 9; i++)
        {
            LPC_GPIO->FIOSET = LED;
            for (j = 0; j < 100000; j++)
                ;
            LED << 1;
        }
        LED = 0x00000010;
        for (i = 1; i < 9; i++)
        {
            LPC_ GPIO0->FIOCLR = LED;
            for (j = 0; j < 10000; j++)
                ;
            LED << 1;
        }
    }
}