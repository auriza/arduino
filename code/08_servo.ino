/*  08. Servo
        https://lastminuteengineers.com/servo-motor-arduino-tutorial/
*/
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  Serial.println("Type an angle (0-180), then press [Enter]");
}

void loop() {
  while (!Serial.available());          // wait until available

  int angle = Serial.parseInt();
  Serial.println(angle);
  servo.write(angle);
}
