.global _start

_start:

	// 设置栈，以便调用c函数
	ldr	sp, =0x30000000	
	bl main

halt:
	b halt

