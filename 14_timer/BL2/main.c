#include "stdio.h"
#include "uart.h"
#include "int.h"
#include "timer.h"

int main()
{	
	// ��ʼ������
	uart_init();

	// �ж���س�ʼ��
	system_initexception();						

	// ����timer
	timer_request();
	
	while (1){}

	return 0;
}