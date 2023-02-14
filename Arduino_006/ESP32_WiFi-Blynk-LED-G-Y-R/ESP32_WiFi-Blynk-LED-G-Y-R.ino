#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLxhmmM7NZ"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
DHT dht(17, DHT11);
char auth[] = "P5qApX9kWy38GaeayQ4N7Vo79qpO8Ady";
char ssid[] = "@_PTL";
char pass[] = "0936185130";
float t,h=0;
BlynkTimer timer;
void myTimerEvent()
{
  Blynk.virtualWrite(V1,t);
  Blynk.virtualWrite(V2,h);
}
BLYNK_WRITE(V14)
{
 digitalWrite(14,param.asInt()); 
}
BLYNK_WRITE(V27)
{
 digitalWrite(27,param.asInt()); 
}
BLYNK_WRITE(V12)
{
 digitalWrite(12,param.asInt()); 
}
void setup()
{
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, myTimerEvent);
}
void loop()
{
  delay(500);
  h = dht.readHumidity();
  t = dht.readTemperature();
  Blynk.run();
   timer.run();
}
