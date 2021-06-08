#include "print.h"
extern "C" void kernel_main() {
	terminal_clear();
	terminal_setcolor(YELLOW, BLACK);
	terminal_writestring((char*)"Welcome to the first boot of DiplodocOS Vulnerable Kernel using c++ code :)\n\n");
	char* rainbow_message = (char*)"This message should appear in rainbow colors, it should have the background and foreground colors changing as well as some auto inserted newlines.";
	for (u16 i = 0; true; ++i) {
		char character = (u8)rainbow_message[i];
		if (character == '\0')
			return;
        terminal_setcolor(i%16, i+14%16);
		terminal_putchar(character);
	}
}