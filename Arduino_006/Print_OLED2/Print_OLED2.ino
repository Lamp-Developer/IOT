#define s1 13
#define s2 5 
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"    // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL

int num ;

void setup() {
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(27,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);

  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_24);

}
void loop() {
  display.clear();
  display.drawString(60,14,String(num));
  display.display();
  if(!digitalRead(s1)){
   num++;
   if(num>9)num=9;
  while(!digitalRead(s1)){delay(10);} 
  }
   if(!digitalRead(s2)){
   num--;
   if(num<0)num=0;
  while(!digitalRead(s2)){delay(10);} 
  }
 if(num>=7){
    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    delay(10);
  }else if(num>=4){
    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,0);
    delay(10);
  }else if(num>=1){
    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    delay(10);
  }else{
    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,0);
    delay(10);
  }
}
