#include "print.h"
extern "C" void kernel_main() {
	print_clear();
	print_set_color(YELLOW, BLACK);
	print_str((char*)"Welcome to the first boot of DiplodocOS Vulnerable Kernel using c++ code :)\n\n");
	char* rainbow_message = (char*)"This message should appear in rainbow colors, it should have the background and foreground colors changing aswell as some auto inserted newlines.";
	for (u16 i = 0; true; ++i) {
		char character = (u8)rainbow_message[i];
		if (character == '\0')
			return;
		print_set_color(i%16, i+14%16);
		print_char(character);
	}
}