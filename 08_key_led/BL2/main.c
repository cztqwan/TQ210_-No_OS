
// LED
#define 	GPJ0CON 	(*(volatile unsigned long *) 0xE0200060)
#define 	GPJ0DAT		(*(volatile unsigned long *) 0xE0200064)

// KEY
#define 	GPH0CON 	(*(volatile unsigned long *) 0xE0200C00)
#define 	GPH0DAT		(*(volatile unsigned long *) 0xE0200C04)
#define 	GPH2CON 	(*(volatile unsigned long *) 0xE0200C40)
#define 	GPH2DAT		(*(volatile unsigned long *) 0xE0200C44)

#define 	GPJ0_0_OUTPUT 	(1<<(3*4))
#define 	GPJ0_1_OUTPUT 	(1<<(4*4))

#define 	GPH0_0_INTPUT 	~(0xf<<(0*4))
#define 	GPH0_1_INTPUT 	~(0xf<<(1*4))
#define 	GPH0_2_INTPUT 	~(0xf<<(2*4))
#define 	GPH0_3_INTPUT 	~(0xf<<(3*4))
#define 	GPH0_4_INTPUT 	~(0xf<<(4*4))
#define 	GPH0_5_INTPUT 	~(0xf<<(5*4))

#define 	GPH2_6_INTPUT 	~(0xf<<(6*4))
#define 	GPH2_7_INTPUT 	~(0xf<<(7*4))

// 延时函数
void delay(unsigned long count)
{
	volatile unsigned long i = count;
	while (i--)
		;
}

void main()
{
	unsigned long dat0;
	unsigned long dat1;

	// LED:设置寄存器GPJ0CON使GPJ0_3/4引脚为输出功能
	GPJ0CON = GPJ0_0_OUTPUT|GPJ0_1_OUTPUT;
	
	// KEY：设置寄存器GPH0CON使GPH0_1/2/3/4/5引脚为输入功能
	// KEY：设置寄存器GPH2CON使GPH2_4/7引脚为输入功能
	GPH0CON = GPH0_0_INTPUT&GPH0_1_INTPUT&GPH0_2_INTPUT&GPH0_3_INTPUT&GPH0_4_INTPUT&GPH0_5_INTPUT;
	GPH2CON = GPH2_6_INTPUT&GPH2_7_INTPUT;


	while(1)
	{
		// 读取KEY相关的引脚值，用于判断KEY是否被按下
		dat0 = GPH0DAT;
		dat1 = GPH2DAT;

		// 判断KEY1:GPH0_0
		if(dat0 & (1<<0))				// KEY1被按下，则LED1亮，否则LED1灭
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// 判断KEY2:GPH0_1
		if(dat0 & (1<<1))				// KEY2被按下，则LED2亮，否则LED2灭
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;


		// 判断KEY3:GPH0_2
		if(dat0 & (1<<2))				// KEY3被按下，则LED1亮，否则LED1灭
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// 判断KEY4:GPH0_3
		if(dat0 & (1<<3))				// KEY4被按下，则LED2亮，否则LED2灭
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;
		
		// 判断KEY5:GPH0_4
		if(dat0 & (1<<4))				// KEY5被按下，则LED1亮，否则LED1灭
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// 判断KEY6:GPH0_5
		if(dat0 & (1<<5))				// KEY6被按下，则LED2亮，否则LED2灭
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;
		
		// 判断KEY7:GPH2_6
		if(dat1 & (1<<6))				// KEY7被按下，则LED1亮，否则LED1灭
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// 判断KEY8:GPH2_7
		if(dat1 & (1<<7))				// KEY8被按下，则LED2亮，否则LED2灭
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;

	}
}


