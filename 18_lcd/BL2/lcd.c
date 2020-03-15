#define GPF0CON			(*(volatile unsigned long *)0xE0200120)
#define GPF1CON			(*(volatile unsigned long *)0xE0200140)
#define GPF2CON			(*(volatile unsigned long *)0xE0200160)
#define GPF3CON			(*(volatile unsigned long *)0xE0200180)

#define GPD0CON			(*(volatile unsigned long *)0xE02000A0)
#define GPD0DAT			(*(volatile unsigned long *)0xE02000A4)

#define CLK_SRC1		(*(volatile unsigned long *)0xe0100204)
#define CLK_DIV1		(*(volatile unsigned long *)0xe0100304)
#define DISPLAY_CONTROL	(*(volatile unsigned long *)0xe0107008)

#define VIDCON0			(*(volatile unsigned long *)0xF8000000)
#define VIDCON1			(*(volatile unsigned long *)0xF8000004)
#define VIDTCON2		(*(volatile unsigned long *)0xF8000018)
#define WINCON0 		(*(volatile unsigned long *)0xF8000020)
#define WINCON2 		(*(volatile unsigned long *)0xF8000028)
#define SHADOWCON 		(*(volatile unsigned long *)0xF8000034)
#define VIDOSD0A 		(*(volatile unsigned long *)0xF8000040)
#define VIDOSD0B 		(*(volatile unsigned long *)0xF8000044)
#define VIDOSD0C 		(*(volatile unsigned long *)0xF8000048)

#define VIDW00ADD0B0 	(*(volatile unsigned long *)0xF80000A0)
#define VIDW00ADD1B0 	(*(volatile unsigned long *)0xF80000D0)

#define VIDTCON0 		(*(volatile unsigned long *)0xF8000010)
#define VIDTCON1 		(*(volatile unsigned long *)0xF8000014)

#define HSPW 			(0)
#define HBPD			(40 - 1)
#define HFPD 			(5 - 1)
#define VSPW			(0)
#define VBPD 			(8 - 1)
#define VFPD 			(8 - 1)

// FB��ַ
#define FB_ADDR			(0x28000000)
#define ROW				(272)
#define COL				(480)
#define HOZVAL			(COL-1)
#define LINEVAL			(ROW-1)

// ��ʼ��LCD
void lcd_init(void)
{
	// ������������LCD����
	GPF0CON = 0x22222222;
	GPF1CON = 0x22222222;
	GPF2CON = 0x22222222;
	GPF3CON = 0x22222222;

	// �򿪱���
	GPD0CON  = (GPD0CON & ~0xF) | (0x1 << 0);
	GPD0DAT |= 1;

	// 10: RGB=FIMD I80=FIMD ITU=FIMD
	DISPLAY_CONTROL = 2<<0;

	// bit[26~28]:ʹ��RGB�ӿ�
	// bit[18]:RGB ����
	// bit[2]:ѡ��ʱ��ԴΪHCLK_DSYS=166MHz
	VIDCON0 &= ~( (3<<26)|(1<<18)|(1<<2) );

	// bit[1]:ʹ��lcd������
	// bit[0]:��ǰ֡������ʹ��lcd������
	VIDCON0 |= ( (1<<0)|(1<<1) );

	// bit[6]:ѡ����Ҫ��Ƶ
	// bit[6~13]:��Ƶϵ��Ϊ15����VCLK = 166M/(14+1) = 11M
	VIDCON0 |= 14<<6 | 1<<4;


	// H43-HSD043I9W1.pdf(p13) ʱ��ͼ��VSYNC��HSYNC���ǵ�����
	// s5pv210оƬ�ֲ�(p1207) ʱ��ͼ��VSYNC��HSYNC���Ǹ�������Ч��������Ҫ��ת
	VIDCON1 |= 1<<5 | 1<<6;

	// ����ʱ��
	VIDTCON0 = VBPD<<16 | VFPD<<8 | VSPW<<0;
	VIDTCON1 = HBPD<<16 | HFPD<<8 | HSPW<<0;
	// ���ó���
	VIDTCON2 = (LINEVAL << 11) | (HOZVAL << 0);

	// ����windows1
	// bit[0]:ʹ��
	// bit[2~5]:24bpp
	WINCON0 |= 1<<0;
	WINCON0 &= ~(0xf << 2);
	WINCON0 |= (0xB<<2) | (1<<15);

#define LeftTopX     0
#define LeftTopY     0
#define RightBotX   479
#define RightBotY   271

	// ����windows1����������
	VIDOSD0A = (LeftTopX<<11) | (LeftTopY << 0);
	VIDOSD0B = (RightBotX<<11) | (RightBotY << 0);
	VIDOSD0C = (LINEVAL + 1) * (HOZVAL + 1)/4;


	// ����fb�ĵ�ַ
	VIDW00ADD0B0 = FB_ADDR;
	VIDW00ADD1B0 = (((HOZVAL + 1)*4 + 0) * (LINEVAL + 1)) & (0xffffff);

	// ʹ��channel 0��������
	SHADOWCON = 0x1;
}


// ���
void lcd_draw_pixel(int row, int col, int color)
{
	unsigned long * pixel = (unsigned long  *)FB_ADDR;

	*(pixel + row * COL + col) = color;

}

// ����
void lcd_clear_screen(int color)
{
	int i, j;

	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			lcd_draw_pixel(i, j, color);

}

// ������
void lcd_draw_hline(int row, int col1, int col2, int color)
{
	int j;

	// ���row�У���j��
	for (j = col1; j <= col2; j++)
		lcd_draw_pixel(row, j, color);

}

// ������
void lcd_draw_vline(int col, int row1, int row2, int color)
{
	int i;
	// ���i�У���col��
	for (i = row1; i <= row2; i++)
		lcd_draw_pixel(i, col, color);

}

// ��ʮ��
void lcd_draw_cross(int row, int col, int halflen, int color)
{
	lcd_draw_hline(row, col-halflen, col+halflen, color);
	lcd_draw_vline(col, row-halflen, row+halflen, color);
}

// ��Բ
void lcd_draw_circle(int row,int col,int halflen, int color)
{
	int a,b;
	int di;
	a=0;b=halflen;	  
	di=3-(halflen<<1);             //�ж��¸���λ�õı�־
	while(a<=b)
	{
		lcd_draw_pixel(row+a,col-b, color);             //5
 		lcd_draw_pixel(row+b,col-a, color);             //0           
		lcd_draw_pixel(row+b,col+a, color);             //4               
		lcd_draw_pixel(row+a,col+b, color);             //6 
		lcd_draw_pixel(row-a,col+b, color);             //1       
 		lcd_draw_pixel(row-b,col+a, color);             
		lcd_draw_pixel(row-a,col-b, color);             //2             
  		lcd_draw_pixel(row-b,col-a, color);             //7     	         
		a++;
		//ʹ��Bresenham�㷨��Բ     
		if(di<0){
			di += 4*a+6;	  
		}
		else
		{
			di += 10+4*(a-b);   
			b--;
		} 						    
	}
} 				
