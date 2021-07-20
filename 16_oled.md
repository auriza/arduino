# 16. OLED display

![](gfx/16_iot.png)

- Wemos D1 mini ([setup](https://github.com/auriza/arduino/blob/main/00_arduino.md#wemos-d1-mini-esp8266))
- OLED 128x64 SSD1306 (library: `Adafruit_SSD1306_Wemos_Mini_OLED`)
- LM35 temperature sensor

```
/*  16. OLED display
    https://lastminuteengineers.com/oled-display-arduino-tutorial/
*/
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(-1);

void setup() {
  Serial.begin(115200);
  oled.begin();
  oled.clearDisplay();
  oled.setTextColor(WHITE, BLACK);
}

void loop() {
  float Tc = get_temp();
  show_temp(Tc);
  delay(5000);
}

float get_temp() {
  float mV = analogRead(A0)/1024.0 * 3300;          // 10 mV/°C
  return mV / 10;
}

void show_temp(float Tc) {
  Serial.println(Tc);
  oled.setCursor(0, 0);
  oled.print(Tc);
  oled.print(" C");
  oled.display();
}
```
