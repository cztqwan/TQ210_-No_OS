#include "uart.h"

#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

int main()
{	
	unsigned char c;

	GPJ0CON = 0x00011000;		// ��������
	uart_init();       //���ڳ�ʼ��

	while(1)
	{
		c = getc();
		putc(c);
		if((c == 'F')||(c == 'f')) //������F����fʱ������
		{
			GPJ0DAT = 0x18;			// LED on
		}
		if((c == 'D')||(c == 'd')) //������D����dʱ������
		{
			GPJ0DAT = 0;			// LED off
		}
	}
	return 0;
}
