#include <LPC17xx.h>
#include <stdio.h>

#define FIRST_SEG 0xF87FFFFF
#define SECOND_SEG 0xF8FFFFFF
#define THIRD_SEG 0xF97FFFFF
#define FOURTH_SEG 0xF97FFFFF
#define DISABLE_ALL 0xFA7FFFFF

unsigned int dig1 = 0x00, dig2 = 0x00, dig3 = 0x00, dig4 = 0x00;
unsigned int twenty_count = 0x00, dig_count = 0x00, temp1 = 0x00;
unsigned char array_dec[10] =
    {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0X7F, 0X6F};
unsigned char tmr() _flg = 0x00, one_sec_flg = 0x00;
unsigned long int temp3 = 0x00;

void delay()
{
    unsigned int i = 0;
    for (i = 0; i < count; i++)
        ;
    if (twenty_count == 1000)
    {
        one_sec_flg = 0xFF;
        twenty_count = 0x00;
    }
    else
        twenty_count += 1;
}

void dispaly()
{
    if (dig_count == 0x01)
    {
        temp1 = dig1;
        LPC_GPIO1->FIOPIN = FIRST_SEG;
    }
    else if (dig_count == 0x02)
    {
        temp1 = dig2;
        LPC_GPIO1->FIOPIN = SECOND_SEG;
    }
    else if (dig_count == 0x03)
    {
        temp1 = dig3;
        LPC_GPIO1->FIOPIN = THIRD_SEG;
    }
    else if (dig_count == 0x04)
    {
        temp1 = dig4;
        LPC_GPIO1->FIOPIN = FOURTH_SEG;
    }

    temp1 &= 0x0F;
    temp2 = array_dec[temp1];
    temp2 <<= 4;
    LPC_GPIO0->FIOPIN = temp2;
    for (i = 0; i < 500; i++)
        ;
    LPC_GPIO0->FIOCLR = 0x00000FF0;
    // LPC_GPIO1->FIOPIN = DISABLE_ALL;
}

int main()
{
    SystemInit();
    SystemCoreClockUpdate();

    LPC_PINCON->PINSEL0 &= 0xFF0000FF;
    LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
    LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;

    LPC_GPIO0->FIODIR |= 0x00000FF0;
    LPC_GPIO1->FIODIR |= 0x78000000;
    LPC_GPIO2->FIODIR |= 0x00000000;

    while (1)
    {
        delay();
        dig_count++;

        if (LPC_GPIO2->FIOPIN & 1 << 12)
        {
            if (dig_count == 0x05)
            {
                dig_count = 0x00;
                one_sec_flg = 0xFF;
            }
            if (one_sec_flg == 0xFF)
            {
                one_sec_flg = 0x00;
                dig1 += 1;
                if (dig1 == 0x0A)
                {
                    dig1 = 0;
                    dig2 += 1;
                    if (dig2 == 0x0A)
                    {
                        dig2 = 0;
                        dig3 += 1;
                        if (dig3 == 0x0A)
                        {
                            dig3 = 0;
                            dig4 += 1;
                            if (dig4 == 0x0A)
                            {
                                dig4 = 0;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (dig_count == 0x05)
            {
                dig_count = 0x00;
                one_sec_flg = 0xFF;
            }
            if (one_sec_flg == 0xFF)
            {
                one_sec_flg = 0x00;
                dig1 += -1;
                if (dig1 == -1)
                {
                    dig1 = 0x09;
                    dig2 += -1;
                    if (dig2 == -1)
                    {
                        dig2 = 0x09;
                        dig3 += -1;
                        if (dig3 == -1)
                        {
                            dig3 = 0x09;
                            dig4 += -1;
                            if (dig4 == -1)
                            {
                                dig4 = 0x09;
                            }
                        }
                    }
                }
            }
        }
        display();
    }
}
