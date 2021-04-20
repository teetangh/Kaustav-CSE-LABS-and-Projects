#include <LPC17xx.h>
unsigned int i, j, c = 0;
int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();
    LPC_PINCON->PINSEL0 &= 0XFF0000FF;
    LPC_GPIO0->FIODIR |= 0x00000FF0;

    while (1)
    {
        for (i = 0; i < 256; i++)
        {
            LPC_GPIO0->FIOPIN = c << 4;
            for (j = 0; j < 30000; j++);
            c++;
        }
    }
}