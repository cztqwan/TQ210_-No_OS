#include "uart.h"

#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

int main()
{	
	unsigned char c;

	GPJ0CON = 0x00011000;		// 配置引脚
	uart_init();       //串口初始化

	while(1)
	{
		c = getc();
		putc(c);
		if((c == 'F')||(c == 'f')) //当按下F或者f时，闪灯
		{
			GPJ0DAT = 0x18;			// LED on
		}
		if((c == 'D')||(c == 'd')) //当按下D或者d时，闪灯
		{
			GPJ0DAT = 0;			// LED off
		}
	}
	return 0;
}
