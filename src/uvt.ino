// uvt.ino

#include <Arduino.h>
#include "pins.hpp"
#include "keyboard.hpp"
#include "display.hpp"
#include "logging.hpp"

void setup()
{
    serial.begin(115200);

    // The board peripheral power control pin needs to be set to HIGH when using the peripheral
    pinMode(BOARD_POWERON, OUTPUT);
    digitalWrite(BOARD_POWERON, HIGH);

    init_tft();
    init_keyboard();

    serial.println("µVT Serial Logger");
}

void loop()
{
    unsigned char c = get_keyboard_key();
    if (c == 0x0A || c == 0x0D) {
        tft.println();
    } else {
        tft.write(c);
    }
}