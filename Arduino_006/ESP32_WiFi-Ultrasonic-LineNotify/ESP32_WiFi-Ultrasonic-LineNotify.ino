#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID  "TMPLxhmmM7NZ"
#include <HCSR04.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TridentTD_LineNotify.h>
#define LINE_TOKEN  "rswUwjEzjC3pQLZiLXLxJ7f4HHQwzX5gaCy1gzoDOFy"
char auth[] = "P5qApX9kWy38GaeayQ4N7Vo79qpO8Ady";
char ssid[] = "@_PTL";
char pass[] = "0936185130";
byte triggerPin = 18;
byte echoPin = 19;
double* distances = 0;
BlynkTimer timer;
void myTimerEvent()
{
  if(distances){
    delay(2000);
    LINE.notify("ค่าของตัววัดระยะ");
    LINE.notify(String(distances[0]));
  }
}
void setup()
{
  HCSR04.begin(triggerPin, echoPin);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  LINE.setToken(LINE_TOKEN);
  LINE.notify("Hello");
}
void loop()
{
 distances = HCSR04.measureDistanceCm();
    Serial.print("1: ");
    Serial.print(distances[0]);
    Serial.println(" cm");
    Serial.println("---");
    delay(2000);
  timer.run();
  Blynk.run();
}
