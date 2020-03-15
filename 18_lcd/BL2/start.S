.text
.global  _start
_start:	
	// 设置栈，以便调用c函数
	ldr	sp, =0x30000000
	
	// 开中断
	mov r0, #0x53			
	msr CPSR_cxsf, r0
	
	bl main				  @调用main函数	
