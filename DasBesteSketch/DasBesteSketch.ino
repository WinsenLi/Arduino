#include <IRremote.h>

#define IR_RECEIVE_PIN 13

int M1Vorne = 7;
int M1Hinten = 6;
int M2Vorne = 5;
int M2Hinten = 4;
int M3Vorne = 11;
int M3Hinten = 10;
int M4Vorne = 9;
int M4Hinten = 8;

void setup() {
 
 pinMode(M1Vorne,OUTPUT);
 pinMode(M1Hinten,OUTPUT);
 pinMode(M2Vorne,OUTPUT);
 pinMode(M2Hinten,OUTPUT);
 pinMode(M3Vorne,OUTPUT);
 pinMode(M3Hinten,OUTPUT);
 pinMode(M4Vorne,OUTPUT);
 pinMode(M4Hinten,OUTPUT);  
 Serial.begin(9600);
 IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);



    if(command == 70) // Vorne
    {

      analogWrite(M1Vorne, 255);
      analogWrite(M1Hinten, 0);

      analogWrite(M2Vorne, 255);
      analogWrite(M2Hinten, 0);

      analogWrite(M3Vorne, 255);
      analogWrite(M3Hinten, 0);

      analogWrite(M4Vorne, 255);
      analogWrite(M4Hinten, 0);
    }
    else if(command == 21) //Hinten
    {

      analogWrite(M1Vorne, 0);
      analogWrite(M1Hinten, 255);

      analogWrite(M2Vorne, 0);
      analogWrite(M2Hinten, 255);

      analogWrite(M3Vorne, 0);
      analogWrite(M3Hinten, 255);

      analogWrite(M4Vorne, 0);
      analogWrite(M4Hinten, 255);
    }
    else if(command == 67) //Rechts
    {
      analogWrite(M1Vorne, 255);
      analogWrite(M1Hinten, 0);

      analogWrite(M2Vorne, 0);
      analogWrite(M2Hinten, 0);

      analogWrite(M3Vorne, 255);
      analogWrite(M3Hinten, 0);

      analogWrite(M4Vorne, 0);
      analogWrite(M4Hinten, 0);
    }
    else if(command == 68) //Links
    {
      analogWrite(M1Vorne, 0);
      analogWrite(M1Hinten, 0);

      analogWrite(M2Vorne, 255);
      analogWrite(M2Hinten, 0);

      analogWrite(M3Vorne, 0);
      analogWrite(M3Hinten, 0);

      analogWrite(M4Vorne, 255);
      analogWrite(M4Hinten, 0);
    }
    else if(command == 64) //Stop
    {
      analogWrite(M1Vorne, 0);
      analogWrite(M1Hinten, 0);

      analogWrite(M2Vorne, 0);
      analogWrite(M2Hinten, 0);

      analogWrite(M3Vorne, 0);
      analogWrite(M3Hinten, 0);

      analogWrite(M4Vorne, 0);
      analogWrite(M4Hinten, 0);
    }

    IrReceiver.resume();
    
  }
}
