int led1 = 12;
int led2 = 14;
int led3 = 27;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
void loop() {
  Serial.println("Test for myarduino");
  for (int x = 1; x < 6; x++) { 
    Serial.print("X = ");
    Serial.println(x); 
    if (x == 1) {
      digitalWrite(led1, HIGH);
    }
    if (x == 2) {
      digitalWrite(led2, HIGH);
    }
    if (x == 3) {
      digitalWrite(led3, HIGH);
    }  
    delay(80);
  }
  for (int x = 6; x > 0; x--) { 
    Serial.print("X = "); 
    Serial.println(x); 
    if (x == 1) {
      digitalWrite(led1, LOW);
    }
    if (x == 2) {
      digitalWrite(led2, LOW);
    }
    if (x == 3) {
      digitalWrite(led3, LOW);
    }
    delay(80);
  }
}
