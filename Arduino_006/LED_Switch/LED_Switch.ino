#define SW1 13    
#define SW2 5     
#define SW3 23    
#define ledG 12   
#define ledY 14   
#define ledR 27  
int swPin[] = {SW1, SW2, SW3};   
int ledPin[] = {ledG, ledY, ledR}; 
bool st[3];      
void setup()
{
  for(int i=0;i<=2;i++)        
    pinMode(swPin[i],INPUT);
  for(int i=0;i<=2;i++)         
    pinMode(ledPin[i],OUTPUT);
}
void loop()
{
  for(int i = 0 ; i<=2 ; i++)
  {
   if(!digitalRead(swPin[i]))        
   {
     st[i] = !st[i];                    
     digitalWrite(ledPin[i],st[i]);     
     while(!digitalRead(swPin[i]))      
      delay(10);                       
   }
  }
}
