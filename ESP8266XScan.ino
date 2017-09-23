/*
 *  This sketch demonstrates how to scan WiFi networks which gives extensive infornation about the AP like MAC address,RSSI and Encryption. 

 */
#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  Serial.println("WiFI XScanner V0.1");
  Serial.println("Scanning.....");
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("Scanning done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" Networks found");
 
    for (int i = 0; i < n; ++i) 
    {
      // Print SSID and RSSI for each network found
      Serial.print("|");
      Serial.print(i + 1);
      Serial.print(" SSID: ");
      Serial.print(WiFi.SSID(i));
       Serial.print(" MAC: ");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.print(" RSSI:");
      Serial.print(WiFi.RSSI(i));
      Serial.print("db ENC:");
      switch(WiFi.encryptionType(i))
      {
        case ENC_TYPE_NONE:
              Serial.print("OPEN|");
        case ENC_TYPE_WEP:
              Serial.print("WEP|");
        case ENC_TYPE_TKIP:
              Serial.print("TKIP|");
        case ENC_TYPE_CCMP:
              Serial.print("CCMP|");
        case ENC_TYPE_AUTO:
              Serial.println("");
      }
      delay(100);
    }
  }
  Serial.println("---");

  // Wait a bit before scanning again
  delay(5000);
}
