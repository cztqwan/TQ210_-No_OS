#include "stdio.h"
#include "uart.h"
#include "adc.h"

int main()
{	
	// ³õÊ¼»¯´®¿Ú
	uart_init();
	
	// ²âÊÔADC
	adc_test();
	
	while (1){}

	return 0;
}