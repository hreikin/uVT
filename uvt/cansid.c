/*
Copyright 2017 64 https://github.com/64/cansid

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do 
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
*/
#include <stddef.h>
#include <stdint.h>

#include "cansid.h"

#define ESC '\x1B'

struct cansid_state cansid_init(void)
{
	struct cansid_state rv = {
		.state = CANSID_ESC,
		.style = 0x0F,
		.next_style = 0x0F
	};
	return rv;
}

static inline unsigned char cansid_convert_color(unsigned char color)
{
	const unsigned char lookup_table[8] = { 0, 4, 2, 6, 1, 5, 3, 7 };
	return lookup_table[(int)color];
}

struct color_char cansid_process(struct cansid_state *state, char x)
{
	struct color_char rv = {
		.style = state->style,
		.ascii = '\0'
	};
	switch (state->state) {
		case CANSID_ESC:
			if (x == ESC)
				state->state = CANSID_BRACKET;
			else {
				rv.ascii = x;
			}
			break;
		case CANSID_BRACKET:
			if (x == '[')
				state->state = CANSID_PARSE;
			else {
				state->state = CANSID_ESC;
				rv.ascii = x;
			}
			break;
		case CANSID_PARSE:
			if (x == '3') {
				state->state = CANSID_FGCOLOR;
			} else if (x == '4') {
				state->state = CANSID_BGCOLOR;
			} else if (x == '0') {
				state->state = CANSID_ENDVAL;
				state->next_style = 0x0F;
			} else if (x == '1') {
				state->state = CANSID_ENDVAL;
				state->next_style |= (1 << 3);
			} else if (x == '=') {
				state->state = CANSID_EQUALS;
			} else {
				state->state = CANSID_ESC;
				state->next_style = state->style;
				rv.ascii = x;
			}
			break;
		case CANSID_BGCOLOR:
			if (x >= '0' && x <= '7') {
				state->state = CANSID_ENDVAL;
				state->next_style &= 0x1F;
				state->next_style |= cansid_convert_color(x - '0') << 4;
			} else {
				state->state = CANSID_ESC;
				state->next_style = state->style;
				rv.ascii = x;
			}
			break;
		case CANSID_FGCOLOR:
			if (x >= '0' && x <= '7') {
				state->state = CANSID_ENDVAL;
				state->next_style &= 0xF8;
				state->next_style |= cansid_convert_color(x - '0');
			} else {
				state->state = CANSID_ESC;
				state->next_style = state->style;
				rv.ascii = x;
			}
			break;
		case CANSID_EQUALS:
			if (x == '1') {
				state->state = CANSID_ENDVAL;
				state->next_style &= ~(1 << 3);
			} else {
				state->state = CANSID_ESC;
				state->next_style = state->style;
				rv.ascii = x;
			}
			break;
		case CANSID_ENDVAL:
			if (x == ';') {
				state->state = CANSID_PARSE;
			} else if (x == 'm') {
				// Finish and apply styles
				state->state = CANSID_ESC;
				state->style = state->next_style;
			} else {
				state->state = CANSID_ESC;
				state->next_style = state->style;
				rv.ascii = x;
			}
			break;
		default:
			break;
	}
	return rv;
}
