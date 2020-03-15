CROSS_COMPILE = arm-linux-
CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
AR      = $(CROSS_COMPILE)ar
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

INCLUDEDIR 	:= $(shell pwd)/include
CFLAGS 		:= -Wall -O2 -fno-builtin
CPPFLAGS   	:= -nostdinc -I$(INCLUDEDIR)

export 	CC AR LD OBJCOPY OBJDUMP INCLUDEDIR CFLAGS CPPFLAGS

objs := start.o main.o uart.o audio.o lib/libc.a

BL2.bin: $(objs)
	${LD} -Tsdram.lds -o BL2.elf $^
	${OBJCOPY} -O binary BL2.elf BL2.bin
	${OBJDUMP} -D BL2.elf > BL2_elf.dis

.PHONY : lib/libc.a
lib/libc.a:
	cd lib; make; cd .
	
%.o : %.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o : %.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<  

clean:
	make  clean -C lib
	rm *.o *.elf *.bin *.dis -f
