#include "types.h"
#pragma once

enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHT_GRAY,
	DARK_GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	PINK,
	YELLOW,
	WHITE,
};

void terminal_clear();
void terminal_putchar(char);
void terminal_writestring(char*);
void terminal_setcolor(u8, u8);