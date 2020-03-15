#include "stdio.h"
#include "uart.h"
#include "int.h"
#include "timer.h"

int main()
{	
	// 初始化串口
	uart_init();

	// 中断相关初始化
	system_initexception();						

	// 设置timer
	timer_request();
	
	while (1){}

	return 0;
}