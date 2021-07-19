/*  13. Relay
        https://tinyurl.com/yhee9suc
        https://lastminuteengineers.com/one-channel-relay-module-arduino-tutorial
*/
#define RELAY 2

void setup() {
  pinMode(RELAY, OUTPUT);
}

void loop() {
  digitalWrite(RELAY, HIGH);            // activate relay
  delay(1000);
  digitalWrite(RELAY, LOW);             // deactivate relay
  delay(3000);
}

