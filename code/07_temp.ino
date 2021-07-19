/*  07. LM35 temperature sensor
        https://www.ti.com/lit/ds/symlink/lm35.pdf
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  float volt = getVoltage(A0);
  float degC = volt * 100.0;            // LM35 output: 0 mV + 10 mV/°C

  Serial.print(volt);
  Serial.print(", ");
  Serial.println(degC);

  delay(1000);
}

// convert analog input value (0--1023) back to voltage value (0.0--5.0V)
float getVoltage(int pin) {
  return (analogRead(pin)/1024.0 * 5);
}
