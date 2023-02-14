#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"    // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  
int num = 0;
void setup() {
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}
void loop() {
 display.clear();
 display.setFont(ArialMT_Plain_16);
 display.drawString(14, 6, "Mr.Thanyawit");
  display.setFont(ArialMT_Plain_24);
 display.drawString(57, 25, String(num));num++; 
 if (num>9)
      num = 0;
 display.display();
 delay(500);
 }
