#include "stdio.h"
#include "uart.h"
#include "adc.h"

int main()
{	
	// ��ʼ������
	uart_init();
	
	// ����ADC
	adc_test();
	
	while (1){}

	return 0;
}