#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>       // Hardware-specific library

extern TFT_eSPI tft; // Declare TFT_eSPI object
// extern TFT_eSPI* tft;
// TFT_eSPI tft;

#define DEFAULT_TEXT_COLOUR     TFT_WHITE
#define DEFAULT_BG_COLOUR       TFT_BLACK
#define DEFAULT_TEXT_SIZE       1

#define CURRENT_WIDTH (tft.width())
#define CURRENT_HEIGHT (tft.height())
#define RIGHT_EDGE (tft.width() - 1)
#define BOTTOM_EDGE (tft.height() - 1)
#define COLUMN_SIZE (currentTextSize * 6)
#define ROW_SIZE (currentTextSize * 8)
#define MAX_COLUMNS (tft.width() / COLUMN_SIZE)
#define MAX_ROWS (tft.height() / ROW_SIZE)
#define CURRENT_COLUMN (tft.getCursorX() / COLUMN_SIZE)
#define CURRENT_ROW (tft.getCursorY() / ROW_SIZE)

void init_tft();
void print_font();

#endif // DISPLAY_H