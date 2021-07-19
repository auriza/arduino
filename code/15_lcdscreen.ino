/* 15. LCD screen
       https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);    // rs, en, d4, d5, d6, d7

void setup() {
  lcd.begin(16, 2);                     // chars, rows
  lcd.clear();
  lcd.print("Hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis());
}

