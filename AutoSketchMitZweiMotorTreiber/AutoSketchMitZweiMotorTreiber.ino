#include <IRremote.h>

#define IR_RECEIVE_PIN 13

int M1Vorne = 7;
int M1Hinten = 6;
int M2Vorne = 4;
int M2Hinten = 5;

int M3Vorne = 10;
int M3Hinten = 11;
int M4Vorne = 9;
int M4Hinten = 8;

void setup() {

  pinMode(M1Vorne, OUTPUT);
  pinMode(M1Hinten, OUTPUT);
  pinMode(M2Vorne, OUTPUT);
  pinMode(M2Hinten, OUTPUT);
  pinMode(M3Vorne, OUTPUT);
  pinMode(M3Hinten, OUTPUT);
  pinMode(M4Vorne, OUTPUT);
  pinMode(M4Hinten, OUTPUT);
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
      Vorne();
    }
    else if(command == 21) //Hinten
    {
      Hinten();
    }
    else if(command == 67) //Rechts
    {
      Rechts();
    }
    else if(command == 68) //Links
    {
      Links();
    }
    else if(command == 64) //Stop
    {
      Stop();
    }

    IrReceiver.resume();
    
  }
}

void Vorne()
{
  digitalWrite(M1Vorne, HIGH);
  digitalWrite(M1Hinten, LOW);

  digitalWrite(M2Vorne, HIGH);
  digitalWrite(M2Hinten, LOW);

  digitalWrite(M3Vorne, HIGH);
  digitalWrite(M3Hinten, LOW);

  digitalWrite(M4Vorne, HIGH);
  digitalWrite(M4Hinten, LOW);
}

void Stop()
{
  digitalWrite(M1Vorne, LOW);
  digitalWrite(M1Hinten, LOW);

  digitalWrite(M2Vorne, LOW);
  digitalWrite(M2Hinten, LOW);

  digitalWrite(M3Vorne, LOW);
  digitalWrite(M3Hinten, LOW);

  digitalWrite(M4Vorne, LOW);
  digitalWrite(M4Hinten, LOW);
}

void Hinten()
{
  digitalWrite(M1Vorne, LOW);
  digitalWrite(M1Hinten, HIGH);

  digitalWrite(M2Vorne, LOW);
  digitalWrite(M2Hinten, HIGH);

  digitalWrite(M3Vorne, LOW);
  digitalWrite(M3Hinten, HIGH);

  digitalWrite(M4Vorne, LOW);
  digitalWrite(M4Hinten, HIGH);
}

void Links()
{
  digitalWrite(M1Vorne, HIGH);
  digitalWrite(M1Hinten, LOW);

  digitalWrite(M2Vorne, LOW);
  digitalWrite(M2Hinten, HIGH);

  digitalWrite(M3Vorne, HIGH);
  digitalWrite(M3Hinten, LOW);

  digitalWrite(M4Vorne, LOW);
  digitalWrite(M4Hinten, HIGH);
}

void Rechts()
{
  digitalWrite(M1Vorne, LOW);
  digitalWrite(M1Hinten, HIGH);

  digitalWrite(M2Vorne, HIGH);
  digitalWrite(M2Hinten, LOW);

  digitalWrite(M3Vorne, LOW);
  digitalWrite(M3Hinten, HIGH);

  digitalWrite(M4Vorne, HIGH);
  digitalWrite(M4Hinten, LOW);
}