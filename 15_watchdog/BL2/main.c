#include "stdio.h"
#include "uart.h"
#include "int.h"
#include "wtd.h"

int main()
{	
	// 初始化串口
	uart_init();

	// 中断相关初始化
	system_initexception();						

	// 测试看门狗
	wtd_test();
	
	while (1){}

	return 0;
}