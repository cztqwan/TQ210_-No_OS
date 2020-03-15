
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

// ��ʱ����
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

	// LED:���üĴ���GPJ0CONʹGPJ0_3/4����Ϊ�������
	GPJ0CON = GPJ0_0_OUTPUT|GPJ0_1_OUTPUT;
	
	// KEY�����üĴ���GPH0CONʹGPH0_1/2/3/4/5����Ϊ���빦��
	// KEY�����üĴ���GPH2CONʹGPH2_4/7����Ϊ���빦��
	GPH0CON = GPH0_0_INTPUT&GPH0_1_INTPUT&GPH0_2_INTPUT&GPH0_3_INTPUT&GPH0_4_INTPUT&GPH0_5_INTPUT;
	GPH2CON = GPH2_6_INTPUT&GPH2_7_INTPUT;


	while(1)
	{
		// ��ȡKEY��ص�����ֵ�������ж�KEY�Ƿ񱻰���
		dat0 = GPH0DAT;
		dat1 = GPH2DAT;

		// �ж�KEY1:GPH0_0
		if(dat0 & (1<<0))				// KEY1�����£���LED1��������LED1��
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// �ж�KEY2:GPH0_1
		if(dat0 & (1<<1))				// KEY2�����£���LED2��������LED2��
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;


		// �ж�KEY3:GPH0_2
		if(dat0 & (1<<2))				// KEY3�����£���LED1��������LED1��
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// �ж�KEY4:GPH0_3
		if(dat0 & (1<<3))				// KEY4�����£���LED2��������LED2��
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;
		
		// �ж�KEY5:GPH0_4
		if(dat0 & (1<<4))				// KEY5�����£���LED1��������LED1��
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// �ж�KEY6:GPH0_5
		if(dat0 & (1<<5))				// KEY6�����£���LED2��������LED2��
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;
		
		// �ж�KEY7:GPH2_6
		if(dat1 & (1<<6))				// KEY7�����£���LED1��������LED1��
			GPJ0DAT &= ~(1<<3);
		else
			GPJ0DAT |= (1<<3);

		// �ж�KEY8:GPH2_7
		if(dat1 & (1<<7))				// KEY8�����£���LED2��������LED2��
			GPJ0DAT &= ~(1<<4);
		else
			GPJ0DAT |= 1<<4;

	}
}


