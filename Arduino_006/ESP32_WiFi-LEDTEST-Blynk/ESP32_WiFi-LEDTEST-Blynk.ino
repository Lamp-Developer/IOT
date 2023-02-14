#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLGzsS4a01"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "oLGdO6tupVJuvaXWTw83pIe7tUUeGB7M";
char ssid[] = "@_PTL";
char pass[] = "0936185130";
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}
