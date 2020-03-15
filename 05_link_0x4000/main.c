#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

// —” ±∫Ø ˝
void delay(unsigned long count)
{
	volatile unsigned long i = count;
	while (i--)
		;
}

void main()				//LED …¡À∏
{
	GPJ0CON = 0x00011000;		// ≈‰÷√“˝Ω≈
	while(1)					// …¡À∏
	{
		GPJ0DAT = 0;			// LED on
		delay(0x100000);
		GPJ0DAT = 0x18;			// LED off
		delay(0x100000);
	}
}


