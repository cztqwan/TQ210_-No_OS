CROSS_COMPILE = arm-linux-

sdram.bin: start.o memory.o mmc_relocate.o
	$(CROSS_COMPILE)ld -Tsdram.lds -o sdram.elf $^
	$(CROSS_COMPILE)objcopy -O binary sdram.elf sdram.bin
	$(CROSS_COMPILE)objdump -D sdram.elf > sdram_elf.dis
	gcc mk210_image.c -o mktq210
	./mktq210 sdram.bin BL1.bin
	
%.o : %.S
	$(CROSS_COMPILE)gcc -o $@ $< -c 

%.o : %.c
	$(CROSS_COMPILE)gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis mktq210 -f
