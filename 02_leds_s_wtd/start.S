.globl _start

_start:
	// �رտ��Ź�
	ldr	r0, =0xE2700000
	mov	r1, #0
	str	r1, [r0]

	// ����GPJ0CON��bit[0:15]������GPJ0_3/4����Ϊ�������
	ldr r1, =0xE0200060
	ldr r0, =0x00011000
	str r0, [r1]
	
	mov r2, #0x1000
led_blink:
	// ����GPJ0DAT��bit[0:3]��ʹGPJ0_3/4��������͵�ƽ��LED��
	ldr r1, =0xE0200064
	mov r0, #0
	str r0, [r1]

	// ��ʱ
	mov r0, #0x100000
	bl delay

	// ����GPJ0DAT��bit[0:3]��ʹGPJ0_3/4��������ߵ�ƽ��LED��
	ldr r1, =0xE0200064
	mov r0, #0x18
	str r0, [r1]
    
	// ��ʱ
	mov r0, #0x100000
	bl delay
	
	sub r2, r2, #1
	cmp r2, #0
	bne led_blink

halt:
	b halt



