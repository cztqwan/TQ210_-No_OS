#include "stdio.h"
#include "uart.h"
#include "lcd.h"
#include "bmp.h"

#define WIDTHEIGHT	480
#define HEIGHT	272

int main()
{
	
	// 初始化串口
	uart_init();
	
	printf("Draw picture\r\n");

	// 初始化LCD
	lcd_init();

	// 画图
	lcd_clear_screen(0x0);
	lcd_draw_bmp(gImage_bmp);

	// 画字符
	printf("FriendlyARM\r\n");
	
	return 0;
}