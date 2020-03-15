CROSS_COMPILE = arm-linux-

led.bin: start.o 
	$(CROSS_COMPILE)ld -Ttext 0x0 -o led.elf $^
	$(CROSS_COMPILE)objcopy -O binary led.elf led.bin
	$(CROSS_COMPILE)objdump -D led.elf > led_elf.dis
	gcc mk210_image.c -o mktq210
	./mktq210 led.bin 210.bin
	
%.o : %.S
	$(CROSS_COMPILE)gcc -o $@ $< -c

%.o : %.c
	$(CROSS_COMPILE)gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis mktq210 -f
