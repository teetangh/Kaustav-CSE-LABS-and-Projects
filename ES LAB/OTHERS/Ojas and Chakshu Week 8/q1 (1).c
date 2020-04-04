#include<lpc17xx.h>
#include <stdlib.h>
#include <time.h>
void lcd_init(void);
void write_cmd(void);
void delay_lcd(unsigned int);
void lcd_com(int);
void write_data(void);
void lcd_com(int);
void write_data(void);
void lcd_data(void);
void clear_ports(void);
void lcd_puts(unsigned char *);

unsigned char Msg3[20]={"Roll of dice:"};
unsigned long int temp1=0, temp2=0;

/*Sint main(void)
{
	LPC_PINCON->PINSEL4 &=0xFCFFFFFF;
	LPC_GPIO2->FIODIR &=0xFFFFEFFF;
	srand(0);
	while(1){
	if(LPC_GPIO2->FIOPIN & 1<<12){}
		else{
	lcd_init();
	
	lcd_com(0x80);
	delay_lcd(800);
	lcd_puts(&Msg3[0]);
	k=rand()%6 +1 + '0';
	lcd_com(0xc0);
	delay_lcd(800);
	lcd_puts(&k);
}
}
	}*/
void lcd_init()
{
	LPC_GPIO0->FIODIR|=0x0F<<23 | 1<<27 | 1<<28;
	clear_ports();
	delay_lcd(3200);
	//4bitmode
	
	lcd_com(0x33);
	delay_lcd(800);
	
	lcd_com(0x32);
	delay_lcd(800);
	
	lcd_com(0x28);
	delay_lcd(800);
	
	lcd_com(0x0C); //display on cursor off
	delay_lcd(800);
	
	lcd_com(0x06);  //entry mode set increement cursor right
	delay_lcd(800);
	
	lcd_com(0x01);
	delay_lcd(10000);
	
	return;
}


void clear_ports(void)
{
		//Clearing
		LPC_GPIO0->FIOCLR=0x0f<<23;	//clearing data lines
		LPC_GPIO0->FIOCLR=1<<27;	//clearing RS line
		LPC_GPIO0->FIOCLR=1<<28;	//clearing enable line
}

void delay_lcd(unsigned int r1)
{
	unsigned int r;
	for(r=0;r<r1;r++);
	return;
}

void lcd_com(int temp1)
{
	temp2=temp1&0xf0;
	temp2=temp2<<19;
	write_cmd();
	delay_lcd(30000);
	temp2=temp1&0x0f;
	temp2=temp2<<23;
	write_cmd();
	delay_lcd(30000);
	return;
}

void write_cmd(void)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOCLR=1<<27;
	LPC_GPIO0->FIOSET=1<<28;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR=1<<28;
	return;
}

void lcd_puts(unsigned char *buf1)
{
	unsigned int i=0;
	
	while(buf1[i]!='\0')
	{
		temp1=buf1[i];
		lcd_data();
		delay_lcd(800);
		i++;
		if(i==16)
		{
			lcd_com(0xc0);
			delay_lcd(800);
		}
	}
	
}

void lcd_data(void)
{
	temp2=temp1&0xf0;
	temp2=temp2<<19;
	write_data();
	delay_lcd(30000);
	temp2=temp1&0x0f;
	temp2=temp2<<23;
	write_data();
	delay_lcd(30000);
	return;
}

void write_data(void)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOSET=1<<27;
	LPC_GPIO0->FIOSET=1<<28;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR=1<<28;
	return;
}