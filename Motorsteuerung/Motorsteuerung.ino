#include <AFMotor.h>


AF_DCMotor M1(1); 
AF_DCMotor M2(2);
AF_DCMotor M3(3); 
AF_DCMotor M4(4);

void setup() 
{
  Serial.begin(9600);
  
 

  
}
void loop() 
{
  M1.setSpeed(200);    
  M2.setSpeed(200);    
  M3.setSpeed(200);    
  M4.setSpeed(200);    

 Vorne(); 
 delay(2000);
 Hinten();
 delay(2000);
}


void Vorne()
{
  Serial.println("Vorwärts");
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}
 
void Hinten()
{
  Serial.println("Rückwärts");
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void Links()
{
  Serial.println("Links");
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(FORWARD);
}

void Rechts()
{
  Serial.println("Rechts");
  M1.run(FORWARD);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(BACKWARD);
}