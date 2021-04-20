#include <LPC17xx.h>

unsigned int i, j;
unsigned long int LED;
int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;

    while (1)
    {
        LED = 0x00000010;
        for (i = 0; i < 9; i++)
        {
            LPC_GPIO0->FIOSET = LED;
            for (j = 0; j < 20000; j++);
            LPC_GPIO0->FIOCLR = LED;
            LED <<= 1;
        }
    }
}