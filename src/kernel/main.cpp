#include "print.h"
extern "C" void kernel_main() {
	print_clear();
	print_set_color(YELLOW, BLACK);
	print_str((char*)"Welcome to the first boot of DiplodocOS Vulnerable Kernel using c++ code :)");
}