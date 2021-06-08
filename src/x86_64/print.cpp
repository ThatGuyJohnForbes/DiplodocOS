#include "print.h"

const static u8 VGA_WIDTH = 80;
const static u8 VGA_HEIGHT = 25;

struct vga_entry {
	u8 character;
	u8 color;
};

struct vga_entry* terminal_buffer = (struct vga_entry*)0xb8000;

u8 col = 0;
u8 row = 0;

u8 color = WHITE | BLACK << 4;

void terminal_clearrow(u8 y) {
	struct vga_entry empty = (struct vga_entry)
	{
		.character =  ' ',
		.color = color,
	};

	for (u8 x = 0; x < VGA_WIDTH; ++x)
        terminal_buffer[x + VGA_HEIGHT * y] = empty;
}

void terminal_putentryat(vga_entry character, u8 x, u8 y){
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = character;
}

void terminal_clear() {
	for (u8 y = 0; y < VGA_HEIGHT; ++y)
        terminal_clearrow(y);
}

void terminal_putnewline() {
	col = 0;
	if (row < VGA_HEIGHT - 1) {
		row++;
		return;
	}

	for (u8 x = 1; x < VGA_HEIGHT; ++x) {
		for (u8 y = 0; y < VGA_WIDTH; ++y) {
			struct vga_entry character = terminal_buffer[x+VGA_WIDTH*y];
            terminal_putentryat(character,x,y-1);
		}
	}

    terminal_clearrow(VGA_HEIGHT-1);
}

void terminal_putchar(char character) {
	if (character == '\n') {
        terminal_putnewline();
		return;
	}

	if (col >= VGA_WIDTH) {
        terminal_putnewline();
	}

    terminal_buffer[col + VGA_WIDTH * row] = (struct vga_entry){
		.character = (u8)character,
		.color = color,
	};
	col++;
}

void terminal_writestring(char* str) {
	for (u16 i = 0; true; ++i) {
		char character = (u8)str[i];
		if (character == '\0')
			return;
        terminal_putchar(character);
	}
}

void terminal_setcolor(u8 foreground, u8 background) {
	color = foreground | (background << 4);
}