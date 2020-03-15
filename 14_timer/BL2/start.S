.text
.global  _start
.global IRQ_handle
_start:	
	// ����ջ���Ա����c����
	ldr	sp, =0x30000000
	
	// ���ж�
	mov r0, #0x53			
	msr CPSR_cxsf, r0
	
	bl main				  @����main����	

IRQ_handle:
	// �����ж�ģʽ��ջ
	ldr sp, =0xD0037F80
	// �����ֳ�
	sub lr, lr, #4				
	stmfd sp!, {r0-r12, lr}
	// ��ת���жϴ�������
	bl	irq_handler		
	// �ָ��ֳ�
	ldmfd sp!, {r0-r12, pc}^