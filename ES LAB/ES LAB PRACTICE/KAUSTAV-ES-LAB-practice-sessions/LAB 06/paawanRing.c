#include <LPC17XX.h>

unsigned int i, j, c = 1;
unsigned long LED = 0x00000016;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;

	while (1)
	{
		LPC_GPIO0->FIOPIN = c << 4;
		for (i = 0; i < 30000; i++);
		c <<= 1;
		if (c == 0x100)
			c = 1;
	}
}