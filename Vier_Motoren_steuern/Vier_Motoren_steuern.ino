#include <AFMotor.h>
#include <IRremote.hpp>  

AF_DCMotor M1(1); 
AF_DCMotor M2(2); 
AF_DCMotor M3(3); 
AF_DCMotor M4(4);


void setup() {
  Serial.begin(9600);

  M1.setSpeed(255); 
  M2.setSpeed(255); 
  M3.setSpeed(255);
  M4.setSpeed(255);
}

void loop() {
    


char input = Serial.read();

  switch (input) {
    case '1':
      Serial.println("Vorwärts");
      M1.run(FORWARD);
      M2.run(FORWARD);
      M3.run(FORWARD);
      M4.run(FORWARD);
      break;

    case '2':
      Serial.println("Rückwärts");
      M1.run(BACKWARD);
      M2.run(BACKWARD);
      M3.run(BACKWARD);
      M4.run(BACKWARD);

      break;

    case '3':
      Serial.println("Links");
      M1.run(FORWARD);
      M2.run(BACKWARD);
      M3.run(BACKWARD);
      M4.run(FORWARD);
      delay(500);
      M1.run(RELEASE);
      M2.run(RELEASE);
      M3.run(RELEASE);
      M4.run(RELEASE);
      break;

    case '4':
     Serial.println("Links");
      M1.run(BACKWARD);
      M2.run(FORWARD);
      M3.run(FORWARD);
      M4.run(BACKWARD);
      delay(500);
      M1.run(RELEASE);
      M2.run(RELEASE);
      M3.run(RELEASE);
      M4.run(RELEASE);
      break;

    case '5':
     Serial.println("Stop");
      M1.run(RELEASE);
      M2.run(RELEASE);
      M3.run(RELEASE);
      M4.run(RELEASE);
      delay(1000);
      break;
  }
}
