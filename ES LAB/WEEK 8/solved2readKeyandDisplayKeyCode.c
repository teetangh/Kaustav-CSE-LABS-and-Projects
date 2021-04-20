#include <LPC17xx.h>
void scan(void);

unsigned char col, row, var, flag, key, *ptr;
unsigned long int i, var1, temp, temp3;
int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    LPC_PINCON->PINSEL3 &= 0xFFC03FF;
    LPC_PINCON->PINSEL3 &= 0xF00FFFFF;
    LPC_GPIO2->FIODIR |= 0x00003C00;
    LPC_GPIO1->FIODIR &= 0xF87FFFFF;

    while (1)
    {
        while (1)
        {
            for (row = 1; row < 5; row++)
            {
                if (row == 1)
                    var1 = 0x00000400;
                else if (row == 2)
                    var1 = 0x00000800;
                else if (row == 3)
                    var1 = 0x00001000;
                else if (row == 4)
                    var1 = 0x00002000;

                temp = var1;
                LPC_GPIO2->FIOCLR = 0x00003C00;
                LPC_GPIO2->FIOSET = var1;

                flag = 0;
                scan();
                if (flag == 1)
                    break;
            }
            if (flag == 1)
                break;
        }
    }
}

void scan(void)
{
    unsigned long temp3;

    temp3 = LPC_GPIO0->FIOPIN;
    temp3 &= 0x780000;
    if (temp3 != 0x00000000)
    {
        flag = 1;
        if (temp3 == 0x0080000)
            col = 0;
        else if (temp3 == 0x0100000)
            col = 1;
        else if (temp3 == 0x0020000)
            col = 2;
        else if (temp3 == 0x0400000)
            col = 3;
    }
}

void Display(void)
{
}