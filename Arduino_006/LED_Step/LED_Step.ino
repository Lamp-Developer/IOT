void setup() {
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
}
void loop() {
  digitalWrite(12, 1);                     
  digitalWrite(14, 0);    
  digitalWrite(27, 0);   
  delay(1000);
  digitalWrite(12, 1);                     
  digitalWrite(14, 1);    
  digitalWrite(27, 0);     
  delay(1000);  
  digitalWrite(12, 1);                     
  digitalWrite(14, 1);    
  digitalWrite(27, 1);     
  delay(1000);  
  digitalWrite(12, 1);                     
  digitalWrite(14, 1);    
  digitalWrite(27, 1);     
  delay(1000);  
  digitalWrite(12, 1);                     
  digitalWrite(14, 1);    
  digitalWrite(27, 0);     
  delay(1000);  
  digitalWrite(12, 1);                     
  digitalWrite(14, 0);    
  digitalWrite(27, 0);     
  delay(1000);
  digitalWrite(12, 0);                     
  digitalWrite(14, 0);    
  digitalWrite(27, 0);     
  delay(1000);  
}
