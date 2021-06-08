#include "typedef.h"
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

void print_clear();
void print_char(char);
void print_str(char*);
void print_set_color(u8, u8);