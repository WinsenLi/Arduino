// you need this so you can use the adafruit motor shield library:
#include <AFMotor.h>

// this created our first motor (called "motor") on port 3 of the motorshield:
AF_DCMotor motor(3, MOTOR12_64KHZ);  

// we do it again, this time our second motor will be called "motor2" on port
// 4 of the motorshield:
AF_DCMotor motor2(4, MOTOR12_64KHZ);
// so now we have 2 motors called "motor" and "motor2"

void setup() {
 Serial.begin(9600);           // set up Serial library at 9600 bps
 //Serial.println("Motor test!");
 
 // set the speed to 200 of 255 of "motor".  Note that 0 is stop,
 // 255 is full speed:
 motor.setSpeed(200);    

 // set the speed to 200 of 255 of "motor2":
 motor2.setSpeed(200);
}

void loop() {
 //Serial.print("tick");
 
 motor.run(FORWARD);      // turn it on going forward
 motor2.run(FORWARD);  // motor 2 goes forward as well
 delay(1000);

 //Serial.print("tock");
 motor.run(BACKWARD);     // the other way
 motor2.run(BACKWARD);  //again for motor 2
 delay(1000);
 
 //Serial.print("tack");
 motor.run(RELEASE);      // stopped
 motor2.run(RELEASE);  // command motor 2 to stop
 delay(1000);
}