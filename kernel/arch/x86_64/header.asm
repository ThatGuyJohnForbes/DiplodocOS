section .multiboot_header
header_start:
	; magic number
	dd 0xe85250d6 ; multiboot2
	; arch
	dd 0 ; protected mode x86_64
	; header length
	dd (header_end - header_start)
	; checksum
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

	; end tag
	dd 0
	dd 8
header_end: