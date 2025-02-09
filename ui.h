#include "core_esp8266_features.h"
#ifndef UI_H
#define UI_H

#include <ESP8266WiFi.h>
#include <U8g2lib.h>            // Include screen library

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/14, /*data=*/12, U8X8_PIN_NONE); // Setup screen

/**
 * Initialize the screen
 */
void init_screen() {
  // Setup and write on screen
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tf); // 6 pixels in width, 10 pixels in height
  u8g2.drawUTF8(34, 30, "Who's this");
  u8g2.drawUTF8(37, 40, "pokemon??");
  u8g2.sendBuffer();
  
  delay(5000);

  u8g2.clearBuffer();
  u8g2.drawUTF8(25, 10, "Connection...");
  u8g2.sendBuffer();
}

/**
 * Display the connection screen
 * @param attempt The number of attempts (0 for success, -1 for failure, other for attempts to be displayed)
 */
void attempt_connection_screen(int attempt) {
  u8g2.clearBuffer();

  if (attempt > 0) {
    u8g2.drawUTF8(25, 10, "Connection...");
    for (int i=0; i<=attempt; i++) {
      u8g2.drawUTF8(10*attempt, 42, String(attempt).c_str());
    }
  }

  else if (attempt == 0) {
    u8g2.drawUTF8(34, 10, "Connected!");
  }

  else if (attempt == -1) {
    u8g2.drawUTF8(0, 10, "Connection fail");
  }

  else {
    u8g2.drawUTF8(5, 10, "Unknow error...");
  }

  u8g2.sendBuffer();
}

#endif
