#include "env.h"                // Include the configuration file (Values defined: ssid, password, sha1)
#include "network.h"            // Include the network functions
#include "ui.h"                 // Include the screen functions

#include <ESP8266WiFi.h>        // Include the Wi-Fi library

// Website to read from
const char* host = "raw.githubusercontent.com";  // Website root
const int httpsPort = 443;

WiFiClientSecure client; // Create a secure client

void setup() {
  // Setup and write on screen
  init_screen();

  // Connect to the Wi-Fi + sha1 with the website
  connect_wifi(client, host, httpsPort);

  // Send a GET request for the sound of the pokemon
  String url = "/PokeAPI/cries/main/cries/pokemon/latest/45.ogg";
  get_request(client, host, url);

  // Disconnect from the Wi-Fi
  disconnect_wifi();
  Serial.println("Connection end");
}


void loop() {
  
}
