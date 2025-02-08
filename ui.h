#ifndef UI_H
#define UI_H

#include <ESP8266WiFi.h>
#include <U8g2lib.h>            // Include screen library

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/14, /*data=*/12, U8X8_PIN_NONE); // Setup screen

void init_screen() {
  // Setup and write on screen
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawUTF8(25, 30, "Who's this");
  u8g2.drawUTF8(25, 55, "pokemon??");
  u8g2.sendBuffer();
}

#endif
