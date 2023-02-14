#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLxhmmM7NZ"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 26
CRGB leds[NUM_LEDS];
char auth[] = "P5qApX9kWy38GaeayQ4N7Vo79qpO8Ady";;
char ssid[] = "@_PTL";
char pass[] = "0936185130";
int r,g,b,di = 0;
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
BLYNK_WRITE(V8){
  di = param.asInt();
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
  if(di == 0){
    for(int i=0;i<=7;i++)
      leds[i] = CRGB(0,0,0);
    FastLED.show();
  }
  else{
    for(int i=0;i<=(di-1);i++)
      leds[i] = CRGB(r,g,b);
    for(int h=di;h<=7;h++)
      leds[h] = CRGB(0,0,0);
    FastLED.show();
  }
  Blynk.run();
}
