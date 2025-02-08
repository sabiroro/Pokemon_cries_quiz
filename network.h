#ifndef NETWORK_H
#define NETWORK_H

#include <ESP8266WiFi.h>
#include "env.h"


void connect_wifi(WiFiClientSecure &client, const char* host, const int httpsPort) {
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
  }
}


void disconnect_wifi() {
  WiFi.disconnect();
}


void get_request(WiFiClientSecure &client, const char* host, String url) {
  // Send a GET request for the sound of the pokemon
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
}

#endif
