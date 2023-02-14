#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 26

int pot =0;
CRGB leds[NUM_LEDS];
void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.setBrightness(10);
}
void loop() { 

 pot = map (analogRead(2),0,4095,1,5); 
 if (pot ==1){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(150,0,0);
    FastLED.show();
  }
 }
 
  if (pot ==2){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,150,0); //ผสมสี
    FastLED.show();
  }
 }
 
   if (pot ==3){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(0,0,150);//ผสมสี
    FastLED.show();
  }
 }
  if (pot ==4){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(150,150,0);//ผสมสี
    FastLED.show();
  }
 }
 if (pot ==5){
   for(int i=0;i<=7;i++){
    leds[i] = CRGB(150,0,150);//ผสมสี
    FastLED.show();
  }
 }
 
 }
