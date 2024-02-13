#include <IRremote.h>

#define IR_RECEIVE_PIN 13

int M1Vorne = 7;
int M1Hinten = 6;
int M2Vorne = 5;
int M2Hinten = 4;

void setup() {
 
 pinMode(M1Vorne,OUTPUT);
 pinMode(M1Hinten,OUTPUT);
 pinMode(M2Vorne,OUTPUT);
 pinMode(M2Hinten,OUTPUT);  
 Serial.begin(9600);
 IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);



    if(command == 70)
    {

      analogWrite(M1Vorne, 255);
      analogWrite(M1Hinten, 0);
      analogWrite(M2Vorne, 255);
      analogWrite(M2Hinten, 0);

    }
    else if(command == 21)
    {

      analogWrite(M1Vorne, 0);
      analogWrite(M1Hinten, 255);
      analogWrite(M2Vorne, 0);
      analogWrite(M2Hinten, 255);

    }
    else if(command == 64)
    {
      analogWrite(M1Vorne, 0);
      analogWrite(M1Hinten, 0);
      analogWrite(M2Vorne, 0);
      analogWrite(M2Hinten, 0);
    }

    IrReceiver.resume();
    
  }
}
