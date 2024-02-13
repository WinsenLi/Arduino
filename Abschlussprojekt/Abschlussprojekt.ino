#include <IRremote.hpp>
#include <AFMotor.h>

AF_DCMotor M1(1); // Motor an Anschluss M1
AF_DCMotor M2(2); // Motor an Anschluss M2
AF_DCMotor M3(3); 
AF_DCMotor M4(4);

const int IR_RECEIVE_PIN = A5;  // Dein IR-Empfangspin

void setup() {
  Serial.begin(9600);
  M1.setSpeed(255); // Setze die Geschwindigkeit des Motors 1 (0-255)
  M2.setSpeed(255); // Setze die Geschwindigkeit des Motors 2 (0-255)
  M3.setSpeed(255);
  M4.setSpeed(255);

  // IR-Empfänger aktivieren
  IrReceiver.begin(IR_RECEIVE_PIN);

}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    long resultValue = IrReceiver.decodedIRData.decodedRawData;  // Empfangene Daten
    Serial.println(resultValue);

    if (resultValue == 0xb946ff00 || resultValue == 0x1E61) 
    {
      Vorne();
    } 
    else if (resultValue == 0xFF906F|| resultValue == 0xEA15FF00) 
    {
      Hinten();
    } 
    else if(resultValue == 0xbf40ff00)
    {
      Stop();
    }

    IrReceiver.resume(); // Empfang für das nächste Signal aktivieren
  }
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

void Stop()
{
  Serial.println("Stop");
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

