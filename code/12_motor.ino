/*  12. DC motor
        use switching transistor, Arduino max current only 40 mA per pin
        https://tinyurl.com/yg5x4fkx
        https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial
*/
#define MOTOR   9

void setup() {
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(MOTOR, 255);              // motor on (full speed)
  delay(3000);
  analogWrite(MOTOR, 0);                // motor off
  delay(3000);

  speedUpandDown();
  serialSpeed();
}

void speedUpandDown() {
  for (int i = 0; i <= 255; i++) {      // accelerate
    analogWrite(MOTOR, i);
    delay(20);
  }
  delay(1000);
  for (int i = 255; i >= 0; i--) {      // decelerate
    analogWrite(MOTOR, i);
    delay(20);
  }
}

void serialSpeed() {
  Serial.println("Type a speed (0-255), then press [Enter]");

  while (true) {
    while (!Serial.available());

    int speed = Serial.parseInt();
    speed = constrain(speed, 0, 255);
    Serial.println(speed);
    analogWrite(MOTOR, speed);
  }
}
