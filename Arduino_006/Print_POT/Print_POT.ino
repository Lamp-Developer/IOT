#include <Wire.h>
#include "SSD1306Wire.h"
#define sw1 13
#define sw2 5
SSD1306Wire display(0x3c, SDA, SCL);
int num ,pot = 0;
void setup()
{
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(12,OUTPUT); //LED GREEN
  pinMode(14,OUTPUT); //LED YELLOW
  pinMode(27,OUTPUT); //LED RED
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}
void loop(){
  for (int i=1 ;i<=10 ; i++){
  pot = pot + analogRead(2);
  delay(100);
  }
  pot = pot / 10; 
  pot = map (pot,30,4095,0,100);
   display.clear();
   display.setFont (ArialMT_Plain_24);
   display.drawString(60,14,String(pot));
   display.display();
   delay(500);

   if(!digitalRead(sw1)){
    num++;
    if(num>9)num=9;
    while(!digitalRead(sw1)){delay(10);}
   }

     if(num<=3){
      digitalWrite(12,1);
      digitalWrite(14,0);
      digitalWrite(27,0); 

    }
    else if(num>=4){
      digitalWrite(12,0);
      digitalWrite(14,1);
      digitalWrite(27,0); 
    }
     if(num>6){
      digitalWrite(12,0);
      digitalWrite(14,0);
      digitalWrite(27,1); 
    }
    if(num==9)
    {
      digitalWrite(12,0);
      digitalWrite(14,0);
      digitalWrite(27,0); 
    }
    if(!digitalRead(sw2)){
    num--;
    if(num<0)num=0;
    while(!digitalRead(sw2)){delay(10);}
   }
   if(num==0)
    {
      digitalWrite(12,0);
      digitalWrite(14,0);
      digitalWrite(27,0); 
    }
}
