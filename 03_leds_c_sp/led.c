#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

void delay(int r0)					// —” ±
{
    volatile int count = r0;
    while (count--)
        ;
}

void led_blink()					// LED…¡À∏
{
	GPJ0CON = 0x00011000;			// ≈‰÷√“˝Ω≈
	while(1)							
	{
		GPJ0DAT = 0x18;				// LED on
		delay(0x10000);
		GPJ0DAT = 0;				// LED off
		delay(0x10000);
	}
}

