#include "stdio.h"
#include "uart.h"
#include "int.h"
#include "wtd.h"

int main()
{	
	// ��ʼ������
	uart_init();

	// �ж���س�ʼ��
	system_initexception();						

	// ���Կ��Ź�
	wtd_test();
	
	while (1){}

	return 0;
}