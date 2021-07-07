#include <kernel/tty.h>

extern "C" void kernel_main(void) {
    terminal_initialize();
    //printf("Hello, Kernel has successfully been built and ran!");
}