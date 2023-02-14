#include <ESP32Servo.h>

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"    // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL


Servo myservo; //ประกาศตัวแปรแทน Servo
int pot = 0; //ประกาศตัวแปร pot
void setup()
{
  myservo.attach(25); // ขา 25 (กำหนดขาควบคุม Servo)
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);

}
void loop(){
  pot = analogRead(2); //อ่านค่า analog ขา 2 มาเก็บที่ตัวแปร pot
  pot = map(pot,0,4095,0,180); //map ค่า จาก 0-4095 เป็น 0-180
  myservo.write(pot); // สั่งให้ Servo หมุนไปองศาตามค่า pot
  delay(50); // หน่วงเวลา 50ms

  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(60,14,String(pot)); /// LCD 
  display.display();
}
