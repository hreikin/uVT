#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include <pgmspace.h>
#include <Wire.h>
#include "pins.hpp"
#include "display.hpp"
#include "logging.hpp"

#define LILYGO_KB_SLAVE_ADDRESS     0x55
#define NULL_CHAR font_characters[0]
#define CARRIAGE_RETURN font_characters[13]
#define CTRL_TOGGLE font_characters[224]        // <shift+microphone>
#define ALT_TOGGLE font_characters[4]           // <shift+$>
#define ALT_C font_characters[12]

const unsigned char font_characters[] PROGMEM = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, // 0-15         C0 control codes
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, // 16-31        C0 control codes
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, // 32-47        SP, !, ", #, $, %, &, ', (, ), *, +, ,, -, ., /
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, // 48-63        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, ;, <, =, >, ?
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, // 64-79        @, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, // 80-95        P, Q, R, S, T, U, V, W, X, Y, Z, [, \, ], ^, _
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, // 96-111       `, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, // 112-127      p, q, r, s, t, u, v, w, x, y, z, {, |, }, ~, DEL
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, // 128-143      Ç, ü, é, â, ä, à, å, ç, ê, ë, è, ï, î, ì, Ä, Å
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, // 144-159      É, æ, Æ, ô, ö, ò, û, ù, ÿ, Ö, Ü, ¢, £, ¥, ₧, ƒ
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, // 160-175      á, í, ó, ú, ñ, Ñ, ª, º, ¿, ⌐, ¬, ½, ¼, ¡, «, »
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, // 176-191      ░, ▒, ▓, │, ┤, ╡, ╢, ╖, ╕, ╣, ║, ╗, ╝, ╜, ╛, ┐
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, // 192-207      └, ┴, ┬, ├, ─, ┼, ╞, ╟, ╚, ╔, ╩, ╦, ╠, ═, ╬, ╧
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, // 208-223      ╨, ╤, ╥, ╙, ╘, ╒, ╓, ╫, ╪, ┘, ┌, █, ▄, ▌, ▐, ▀
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, // 224-239      α, ß, Γ, π, Σ, σ, µ, τ, Φ, Θ, Ω, δ, ∞, φ, ε, ∩
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF  // 240-255      ≡, ±, ≥, ≤, ⌠, ⌡, ÷, ≈, °, ∙, ·, √, ⁿ, ², ■, NBSP
};

struct KeyMapping {
    // The following characters should be available to map to an alternative.
    //
    // Default: q w e r t y u i o p a s d f g h j k l z x c v b n m $ <space>
    // Shift:   Q W E R T Y U I O P A S D F G H J K L Z X C V B N M
    // Symbol:  # 1 2 3 ( ) _ - + @ * 4 5 6 / : ; \ " 7 8 9 ? ! , . 0
    unsigned char original;
    unsigned char alternative;
};

static struct KeyMapping alt_characters_table_one[] {
    // qwertyuiop
    {font_characters[113], font_characters[96]},
    {font_characters[119], font_characters[37]},
    {font_characters[101], font_characters[38]},
    {font_characters[114], font_characters[156]},
    {font_characters[116], font_characters[123]},
    {font_characters[121], font_characters[125]},
    {font_characters[117], font_characters[94]},
    {font_characters[105], font_characters[60]},
    {font_characters[111], font_characters[62]},
    {font_characters[112], font_characters[61]},
    // asdfghjkl
    {font_characters[97], font_characters[166]},
    {font_characters[115], font_characters[167]},
    {font_characters[100], font_characters[169]},
    {font_characters[102], font_characters[170]},
    {font_characters[103], font_characters[92]},
    {font_characters[104], font_characters[171]},
    {font_characters[106], font_characters[172]},
    {font_characters[107], font_characters[174]},
    {font_characters[108], font_characters[175]},
    // zxcvbnm$
    {font_characters[122], font_characters[230]},
    {font_characters[120], font_characters[236]},
    {font_characters[99], font_characters[253]},
    {font_characters[118], font_characters[168]},
    {font_characters[98], font_characters[173]},
    {font_characters[110], font_characters[239]},
    {font_characters[109], font_characters[126]},
    {font_characters[36], font_characters[155]},
    // <space>
    {font_characters[32], font_characters[255]},
    // RP
    {font_characters[82], font_characters[158]},
    {font_characters[80], font_characters[247]},
    // #123()_-+@
    {font_characters[35], font_characters[244]},
    {font_characters[49], font_characters[245]},
    {font_characters[50], font_characters[246]},
    {font_characters[51], font_characters[157]},
    {font_characters[40], font_characters[91]},
    {font_characters[41], font_characters[93]},
    {font_characters[95], font_characters[241]},
    {font_characters[45], font_characters[242]},
    {font_characters[43], font_characters[243]},
    {font_characters[64], font_characters[240]},
    // *456/
    {font_characters[42], font_characters[248]},
    {font_characters[52], font_characters[249]},
    {font_characters[53], font_characters[250]},
    {font_characters[54], font_characters[251]},
    {font_characters[47], font_characters[124]},
    //  9,
    {font_characters[57], font_characters[252]},
    {font_characters[44], font_characters[126]},
};

static struct KeyMapping alt_characters_table_two[] {
    // qwertyuiop
    {font_characters[113], font_characters[131]},
    {font_characters[119], font_characters[132]},
    {font_characters[101], font_characters[133]},
    {font_characters[114], font_characters[134]},
    {font_characters[116], font_characters[160]},
    {font_characters[121], font_characters[142]},
    {font_characters[117], font_characters[143]},
    {font_characters[105], font_characters[145]},
    {font_characters[111], font_characters[146]},
    {font_characters[112], font_characters[135]},
    // asdfghjkl
    {font_characters[97], font_characters[128]},
    {font_characters[115], font_characters[225]},
    {font_characters[100], font_characters[130]},
    {font_characters[102], font_characters[136]},
    {font_characters[103], font_characters[137]},
    {font_characters[104], font_characters[138]},
    {font_characters[106], font_characters[144]},
    {font_characters[107], font_characters[139]},
    {font_characters[108], font_characters[140]},
    // zxcvbnm
    {font_characters[122], font_characters[141]},
    {font_characters[120], font_characters[161]},
    {font_characters[99], font_characters[164]},
    {font_characters[118], font_characters[165]},
    {font_characters[98], font_characters[147]},
    {font_characters[110], font_characters[148]},
    {font_characters[109], font_characters[149]},
    // #123()_-+@
    {font_characters[35], font_characters[153]},
    {font_characters[49], font_characters[162]},
    {font_characters[50], font_characters[129]},
    {font_characters[51], font_characters[150]},
    {font_characters[40], font_characters[151]},
    {font_characters[41], font_characters[154]},
    {font_characters[95], font_characters[163]},
    {font_characters[45], font_characters[152]},
    {font_characters[43], font_characters[224]},
    {font_characters[64], font_characters[226]},
    // *456/:;'"
    {font_characters[42], font_characters[227]},
    {font_characters[52], font_characters[228]},
    {font_characters[53], font_characters[229]},
    {font_characters[54], font_characters[231]},
    {font_characters[47], font_characters[232]},
    {font_characters[58], font_characters[233]},
    {font_characters[59], font_characters[234]},
    {font_characters[39], font_characters[235]},
    {font_characters[34], font_characters[237]},
    // 7
    {font_characters[55], font_characters[238]}
};

static struct KeyMapping alt_characters_table_three[] {
    // qwertyuiop
    {font_characters[113], font_characters[179]},
    {font_characters[119], font_characters[180]},
    {font_characters[101], font_characters[181]},
    {font_characters[114], font_characters[182]},
    {font_characters[116], font_characters[183]},
    {font_characters[121], font_characters[184]},
    {font_characters[117], font_characters[185]},
    {font_characters[105], font_characters[186]},
    {font_characters[111], font_characters[187]},
    {font_characters[112], font_characters[188]},
    // asdfghjkl
    {font_characters[97], font_characters[189]},
    {font_characters[115], font_characters[190]},
    {font_characters[100], font_characters[191]},
    {font_characters[102], font_characters[192]},
    {font_characters[103], font_characters[193]},
    {font_characters[104], font_characters[194]},
    {font_characters[106], font_characters[195]},
    {font_characters[107], font_characters[196]},
    {font_characters[108], font_characters[197]},
    // zxcvbnm$
    {font_characters[122], font_characters[198]},
    {font_characters[120], font_characters[199]},
    {font_characters[99], font_characters[200]},
    {font_characters[118], font_characters[201]},
    {font_characters[98], font_characters[202]},
    {font_characters[110], font_characters[203]},
    {font_characters[109], font_characters[204]},
    {font_characters[36], font_characters[205]},
    // #123()_-+@
    {font_characters[35], font_characters[206]},
    {font_characters[49], font_characters[207]},
    {font_characters[50], font_characters[208]},
    {font_characters[51], font_characters[209]},
    {font_characters[40], font_characters[210]},
    {font_characters[41], font_characters[211]},
    {font_characters[95], font_characters[212]},
    {font_characters[45], font_characters[213]},
    {font_characters[43], font_characters[214]},
    {font_characters[64], font_characters[215]},
    // *456/:;'"
    {font_characters[42], font_characters[216]},
    {font_characters[52], font_characters[217]},
    {font_characters[53], font_characters[218]},
    {font_characters[54], font_characters[219]},
    {font_characters[47], font_characters[220]},
    {font_characters[58], font_characters[221]},
    {font_characters[59], font_characters[222]},
    {font_characters[39], font_characters[223]},
    {font_characters[34], font_characters[254]},
    // 789
    {font_characters[55], font_characters[176]},
    {font_characters[56], font_characters[177]},
    {font_characters[57], font_characters[178]},
};
static struct KeyMapping ctrl_characters[] {
    // qwertyuiop
    {font_characters[113], font_characters[17]},
    {font_characters[119], font_characters[23]},
    {font_characters[101], font_characters[5]},
    {font_characters[114], font_characters[18]},
    {font_characters[116], font_characters[20]},
    {font_characters[121], font_characters[25]},
    {font_characters[117], font_characters[21]},
    {font_characters[105], font_characters[9]},
    {font_characters[111], font_characters[15]},
    {font_characters[112], font_characters[16]},
    // asdfghjkl
    {font_characters[97], font_characters[1]},
    {font_characters[115], font_characters[19]},
    {font_characters[100], font_characters[4]},
    {font_characters[102], font_characters[6]},
    {font_characters[103], font_characters[7]},
    {font_characters[104], font_characters[8]},
    {font_characters[106], font_characters[10]},
    {font_characters[107], font_characters[11]},
    {font_characters[108], font_characters[12]},
    // zxcvbnm$
    {font_characters[122], font_characters[26]},
    {font_characters[120], font_characters[24]},
    {font_characters[99], font_characters[3]},
    {font_characters[118], font_characters[22]},
    {font_characters[98], font_characters[2]},
    {font_characters[110], font_characters[14]},
    {font_characters[109], font_characters[13]},
    {font_characters[36], font_characters[127]},
    // <space>
    {font_characters[32], font_characters[27]}
};

static int alt_characters_table_one_size = sizeof(alt_characters_table_one) / sizeof(alt_characters_table_one[0]);
static int alt_characters_table_two_size = sizeof(alt_characters_table_two) / sizeof(alt_characters_table_two[0]);
static int alt_characters_table_three_size = sizeof(alt_characters_table_three) / sizeof(alt_characters_table_three[0]);
static int ctrl_characters_size = sizeof(ctrl_characters) / sizeof(ctrl_characters[0]);

void init_keyboard();
unsigned char get_alternative_char(struct KeyMapping mappings[], int size, unsigned char original);
unsigned char get_keyboard_key();

#endif // KEYBOARD_H