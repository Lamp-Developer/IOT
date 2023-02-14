#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLGzsS4a01"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "oLGdO6tupVJuvaXWTw83pIe7tUUeGB7M";
char ssid[] = "@_PTL";
char pass[] = "0936185130";
BLYNK_WRITE(V14)
{
  digitalWrite(14,param.asInt());
}
BLYNK_WRITE(V27)
{
  digitalWrite(27,param.asInt());
}
void setup()
{
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}
