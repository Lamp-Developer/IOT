#define R 27
#define Y 14
#define G 12
#define sw1 13
#define sw2 5
#define sw3 23
bool s1 = false;
bool s2 = false;
bool s3 = false;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(sw1, INPUT); 
  pinMode(sw2, INPUT); 
  pinMode(sw3, INPUT); 
}
void loop() {
 if(!digitalRead(sw1)){
  s1 = !s1;
  while(!digitalRead(sw1)){digitalWrite(G,s1);delay(10);  }                                                                                                               
 }
 if(!digitalRead(sw2)){
  s2 = !s2;
  while(!digitalRead(sw2)){digitalWrite(Y,s2);delay(10);digitalWrite(G,s2);delay(10);  } 
  }
 if(!digitalRead(sw3)){
  s3 = !s3;
  while(!digitalRead(sw3)){digitalWrite(R,s3);delay(10);digitalWrite(Y,s3);delay(10);digitalWrite(G,s3);delay(10);  } 
 delay(10);
  }
}
