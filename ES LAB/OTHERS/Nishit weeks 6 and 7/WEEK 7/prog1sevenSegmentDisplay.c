#include <LPC17xx.h>
unsigned int seven_seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int dis_count[] = {4, 3, 2, 1};
unsigned int dis_sel[] = {0 << 23, 1 << 23, 2 << 23, 3 << 23};
unsigned int dig_c = 0;
void delay()
{
    unsigned int i;
    for (i = 0; i < 100000; i++)
        ;
}

void display()
{
    LPC_GPIO1->FIOPIN = dis_sel[dig_c];
    LPC_GPIO0->FIOPIN = seven_seg[dis_count[dig_c]] << 4;
}

int main()
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_GPIO0->FIODIR |= 0xFF << 4;
    LPC_GPIO1->FIODIR |= 0xFF << 23;
    while (1)
    {
        dig_c++;
        delay();
        if (dig_c == 5)
            dig_c = 0;
        display();
    }
}