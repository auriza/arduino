/*  09. Flex sensor and servo
        https://lastminuteengineers.com/flex-sensor-arduino-tutorial/
        https://www.arduino.cc/reference/en/libraries/servo/attach/
*/
#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  int flex  = analogRead(A0);
  int angle = map(flex, 750, 950, 0, 180);

  Serial.print(flex);
  Serial.print(", ");
  Serial.println(angle);

  servo.write(angle);
  delay(100);
}
