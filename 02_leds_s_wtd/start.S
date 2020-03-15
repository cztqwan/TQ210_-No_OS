.globl _start

_start:
	// 关闭看门狗
	ldr	r0, =0xE2700000
	mov	r1, #0
	str	r1, [r0]

	// 设置GPJ0CON的bit[0:15]，配置GPJ0_3/4引脚为输出功能
	ldr r1, =0xE0200060
	ldr r0, =0x00011000
	str r0, [r1]
	
	mov r2, #0x1000
led_blink:
	// 设置GPJ0DAT的bit[0:3]，使GPJ0_3/4引脚输出低电平，LED亮
	ldr r1, =0xE0200064
	mov r0, #0
	str r0, [r1]

	// 延时
	mov r0, #0x100000
	bl delay

	// 设置GPJ0DAT的bit[0:3]，使GPJ0_3/4引脚输出高电平，LED灭
	ldr r1, =0xE0200064
	mov r0, #0x18
	str r0, [r1]
    
	// 延时
	mov r0, #0x100000
	bl delay
	
	sub r2, r2, #1
	cmp r2, #0
	bne led_blink

halt:
	b halt




