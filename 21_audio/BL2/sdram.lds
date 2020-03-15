SECTIONS
{
	. = 0x21000000;
	.text : {
		start.o
		* (.text)
	}
	
	.data : {
		* (.data)
	}
	bss_start = .;
	.bss : {
		* (.bss)
	}
	bss_end = .;
}
