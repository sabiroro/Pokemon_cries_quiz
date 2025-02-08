#include "env.h"                // Include the configuration file (Values defined: ssid, password, sha1)
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <U8g2lib.h>            // Include screen library

// Website to read from
const char* host = "raw.githubusercontent.com";  // Website root
const int httpsPort = 443;

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/14, /*data=*/12, U8X8_PIN_NONE); // Setup screen

WiFiClientSecure client; // Create a secure client

void setup() {
  // Setup and write on screen
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawUTF8(25, 30, "Who's this");
  u8g2.drawUTF8(25, 55, "pokemon??");
  u8g2.sendBuffer();

  // Get connection to local WiFi
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(1000);
  Serial.println('\n');
  
  WiFi.begin(ssid, password); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println("...");

  int attempt = 0;
  while ((WiFi.status() != WL_CONNECTED)) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++attempt); Serial.print(' ');

    if (attempt == 15) { // If we wait more than 15 seconds
      Serial.println("\n Connection failed...");
      return;
    }
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  //client.setFingerprint(sha1); // Set the SHA1 fingerprint of the website
  client.setInsecure();
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection to website failed");
    return;
  }
  //Serial.println("Secured request done!");

  // Send a GET request for the sound of the pokemon
  String url = "/PokeAPI/cries/main/cries/pokemon/latest/45.ogg";
  Serial.print("Requête GET : "); Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line == "\r") {  
      break; // Skip HTTP headers
    }
  }

  WiFi.disconnect();
  Serial.println("Connection end");
}


void loop() {
  
}
