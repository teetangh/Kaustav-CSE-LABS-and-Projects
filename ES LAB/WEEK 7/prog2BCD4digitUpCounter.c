#include <LPC17xx.h>
unsigned int seven_seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
// unsigned int dis_count[] = {4, 3, 2, 1};
unsigned int decoder[] = {0<<23, 1<<23, 2<<23, 3<<23};
unsigned int dig1 = 0, dig2 = 0, dig3 = 0, dig4 = 0, temp = 0, i, dis_c = 0, flag;
unsigned int i;

void delay()
{
    for (i = 0; i < 20000; i++);
}

void display()
{
    if (dis_c == 0x01)
    {
        temp = dig1;
        LPC_GPIO1->FIOPIN = decoder[dis_c];
    }
    else if (dis_c == 0x02)
    {
        temp = dig2;
        LPC_GPIO1->FIOPIN = decoder[dis_c];
    }
    else if (dis_c == 0x03)
    {
        temp = dig3;
        LPC_GPIO1->FIOPIN = decoder[dis_c];
    }
    else if (dis_c == 0x04)
    {
        temp = dig4;
        LPC_GPIO1->FIOPIN = decoder[dis_c];
    }

    LPC_GPIO0->FIOPIN = seven_seg[temp]<< 4;
    delay();
    LPC_GPIO0->FIOCLR = 0;
}

int main()
{
    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_GPIO0->FIODIR |= 0xFF0;
    LPC_GPIO1->FIODIR |= 0xF<< 23;
    while (1)
    {
			delay();
        dis_c++;
        if (dis_c == 0x5)
        {
            dis_c = 0;
            flag = 0xFF;
        }
        if (flag == 0xFF)
        {
            dig1++;
            if (dig1 == 0x0A)
            {
                dig1 = 0;
                dig2++;
                if (dig2 == 0x0A)
                {
                    dig2 = 0;
                    dig3++;
                    if (dig3 == 0x0A)
                    {
                        dig3 = 0;
                        dig4++;
                        if (dig4 == 0x0A)
                        {
                            dig4 = 0;
                        }
                    }
                }
            }
        }
        display();
    }
}