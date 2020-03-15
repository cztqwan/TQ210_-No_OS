.text
.global  _start
.global IRQ_handle
_start:	
	// 设置栈，以便调用c函数
	ldr	sp, =0x30000000
	
	// 开中断
	mov r0, #0x53			
	msr CPSR_cxsf, r0
	
	bl main				  @调用main函数	

IRQ_handle:
	// 设置中断模式的栈
	ldr sp, =0xD0037F80
	// 保存现场
	sub lr, lr, #4				
	stmfd sp!, {r0-r12, lr}
	// 跳转到中断处理函数
	bl	irq_handler		
	// 恢复现场
	ldmfd sp!, {r0-r12, pc}^