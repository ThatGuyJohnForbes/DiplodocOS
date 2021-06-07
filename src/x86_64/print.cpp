#include "typedef.h"
#include "print.h"

const static u8 WIDTH = 80;
const static u8 HEIGHT = 25;

struct Char {
	u8 character;
	u8 color;
};

struct Char* buffer = (struct Char*)0xb8000;

u8 col = 0;
u8 row = 0;

u8 color = WHITE | BLACK << 4;

void clear_row(u8 y) {
	struct Char empty = (struct Char)
	{
		character : ' ',
		color : color,
	};

	for (u8 x = 0; x < WIDTH; ++x)
		buffer[x + HEIGHT * y] = empty;
}

void print_clear() {
	for (u8 y = 0; y < HEIGHT; ++y)
		clear_row(y);
}

void print_newline() {
	col = 0;
	if (row < HEIGHT - 1) {
		row++;
		return;
	}

	for (u8 x = 1; x < HEIGHT; ++x) {
		for (u8 y = 0; y < WIDTH; ++y) {
			struct Char character = buffer[x+WIDTH*y];
			buffer[x + WIDTH * (y - 1)] = character;
		}
	}

	clear_row(HEIGHT-1);
}

void print_char(char character) {
	if (character == '\n') {
		print_newline();
		return;
	}

	if (col > WIDTH) {
		print_newline();
	}

	buffer[col + WIDTH * row] = (struct Char){
		character: (u8)character,
		color : color,
	};
	col++;
}

void print_str(char* str) {
	for (u16 i = 0; true; ++i) {
		char character = (u8)str[i];
		if (character == '\0')
			return;

		print_char(character);
	}
}

void print_set_color(u8 foreground, u8 background) {
	color = foreground | (background << 4);
}