# 08. Servo

![](gfx/08_servo.png)

```ino
/*  08. Servo
        https://lastminuteengineers.com/servo-motor-arduino-tutorial
        https://www.arduino.cc/reference/en/libraries/servo/attach
*/
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  Serial.println("Type an angle (0-180), then press [Enter]");
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt();
    Serial.println(angle);
    servo.write(angle);
  }
}
```
