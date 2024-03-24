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
#ifndef CANSID_H
#define CANSID_H

struct cansid_state {
	enum {
		CANSID_ESC,
		CANSID_BRACKET,
		CANSID_PARSE,
		CANSID_BGCOLOR,
		CANSID_FGCOLOR,
		CANSID_EQUALS,
		CANSID_ENDVAL,
	} state;
	unsigned char style;
	unsigned char next_style;
};

struct color_char {
	unsigned char style;
	unsigned char ascii;
};

struct cansid_state cansid_init(void);
struct color_char cansid_process(struct cansid_state *state, char x);

#endif
