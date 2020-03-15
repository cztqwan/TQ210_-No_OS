#include "stdio.h"
#include "uart.h"

#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

int main()
{	
	int a = 0;
	int b = 0;
	char *str = "hello world";

	GPJ0CON = 0x00011000;		// ≈‰÷√“˝Ω≈
	uart_init();
	GPJ0DAT = 0x18;			// LED on
	
	printf("%s\r\n",str);

	while (1)
	{
		printf("please enter two number: \r\n");
		scanf("%d %d", &a, &b);
		printf("\r\n");
		printf("the sum is: %d\r\n", a+b);
		if( a+b == 2 )
		{
			GPJ0DAT = 0x18;			// LED on
		}
		if( a+b == 1 )
		{
			GPJ0DAT = 0;			// LED off
		}
	}

	return 0;
}
