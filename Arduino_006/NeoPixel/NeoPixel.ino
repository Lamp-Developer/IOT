#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 26

CRGB leds[NUM_LEDS];
void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.setBrightness(10);
}
void loop() { 
  for(int g=0;g<=50;g++){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,g,0);
    FastLED.show();
  }
  delay(10);
 }

 for(int g=50;g>=0;g--){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,g,0);
    FastLED.show();
  }
  delay(10);
 }
  for(int b=0;b<=50;b++){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,0,b);
    FastLED.show();
  }
  delay(10);
 }
  for(int b=50;b>=0;b--){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,0,b);
    FastLED.show();
  }
  delay(10);
 }
  for(int r=0;r<=50;r++){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(r,r,0);
    FastLED.show();
  }
  delay(10);
 }

 for(int r=50;r>=0;r--){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(r,r,0);
    FastLED.show();
  }
  delay(10);
 }

}
