// display.cpp

#include "display.hpp"

TFT_eSPI tft = TFT_eSPI(); // Define TFT_eSPI object

void init_tft() {
    // Init the screen and configure it
    tft.init();
    tft.setAttribute(CP437_SWITCH, 1);              // CP437 font correction on to fix off by one bug
    tft.setAttribute(UTF8_SWITCH, 0);               // UTF8 decoding off to enable all CP437 characters within the font to be displayed
    tft.setAttribute(PSRAM_ENABLE, 1);              // PSRAM enabled
    // Config display defaults
    tft.setRotation(1);
    tft.setTextColor(DEFAULT_TEXT_COLOUR);
    tft.fillScreen(DEFAULT_BG_COLOUR);
    // Set "cursor" at top left corner of display (0,0)
    tft.setCursor(0, 0);
    // Turn the backlight on
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
}

void print_font() {
  int row = 0;
  int col = 0;
  int charCount = 0;

  tft.setCursor(0, 0);

  for (int i = 0; i < 256; i++) {
    if (i % 16 == 0) {
      row++;
      col = 0;
      tft.setCursor(0, row * 8);
    }
    if (i == 0x00 || i == 0x0A || i == 0x0D) {
        tft.write(0x20);
    } else {
        tft.write(i);
    }
    col++;
  }
}