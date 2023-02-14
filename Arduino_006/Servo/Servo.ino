#include <ESP32Servo.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"    // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL
Servo myservo; //ประกาศตัวแปรแทน Servo
int pot = 0; //ประกาศตัวแปร pot

void setup(){
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  myservo.attach(25); // ขา 25 (กำหนดขาควบคุม Servo)
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}
void loop(){
  for(int i=1 ; i<=10 ; i++){
    pot = pot+analogRead(2);
    pot = pot/2;
    delay(100);
  }
  pot = map(pot,0,4095,0,180); //map ค่า จาก 0-4095 เป็น 0-180
  myservo.write(pot); // สั่งให้ Servo หมุนไปองศาตามค่า pot
  delay(50); // หน่วงเวลา 50ms
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(60,14,String(pot));
  display.display();

  if(pot>=136){
    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    delay(10);
  }else if(pot>=91){
    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,0);
    delay(10);
  }else if(pot>=46){
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
