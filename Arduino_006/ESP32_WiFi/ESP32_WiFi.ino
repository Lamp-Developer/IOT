#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLxhmmM7NZ"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 26
CRGB leds[NUM_LEDS];
char auth[] = "P5qApX9kWy38GaeayQ4N7Vo79qpO8Ady";
char ssid[] = "@_PTL";
char pass[] = "0936185130";
int r,g,b = 0;
BLYNK_WRITE(V5)
{
  r = param.asInt();
}
BLYNK_WRITE(V6)
{
  g = param.asInt();
}
BLYNK_WRITE(V7)
{
  b = param.asInt();
}
void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  leds[0] = CRGB(r,g,b);
  FastLED.show();
  Blynk.run();
}
