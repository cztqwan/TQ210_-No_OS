#include "stdio.h"
#include "uart.h"
#include "lcd.h"
#include "bmp.h"

#define WIDTHEIGHT	480
#define HEIGHT	272

int main()
{
	
	// ��ʼ������
	uart_init();
	
	printf("Draw picture\r\n");

	// ��ʼ��LCD
	lcd_init();

	// ��ͼ
	lcd_clear_screen(0x0);
	lcd_draw_bmp(gImage_bmp);

	// ���ַ�
	printf("FriendlyARM\r\n");
	
	return 0;
}