#include <Arduino.h>

#include "Http/EspClient.h"
#include "ConnectionWrapper.h"
#include "CloudStorage.h"

CloudStorage<http::Esp8266Request> storage("gil", "123456");

void setup() {
  Serial.begin(115200);
  Serial.println("Begin");
  WifiConnection::tryConnect("The Promised Lan", "251998gil");  
  delay(3 * 1000); // Give some time to connect to wifi
}

void loop() {
  Serial.println("Checking Connection");
  if (WifiConnection::isConnected()) {
    
    int val = storage.get<int>("age");
    
    Serial.print("Got value: ");
    Serial.print(val);
    Serial.println(" . Updating...");
    
    storage.put<int>("age", val + 1);
    
  } else {
    Serial.println("No Connection");
  }

  delay(10000);
}

