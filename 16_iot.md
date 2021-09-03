# 16. IoT ThingSpeak

![](gfx/16_iot.png)

- Wemos D1 mini ([setup](https://github.com/auriza/arduino/blob/main/00_arduino.md#wemos-d1-mini-esp8266))
- OLED 128x64 SSD1306 (library: `Adafruit_SSD1306_Wemos_Mini_OLED`)
- LM35 temperature sensor
- ThingSpeak API (<https://thingspeak.com/channels>)

```ino
/*  16. IoT ThingSpeak
    https://thingspeak.com/channels
    https://www.mathworks.com/help/thingspeak/writedata.html
*/
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SSID  "____"
#define PASS  "________"

Adafruit_SSD1306 oled(-1);

void setup() {
  Serial.begin(115200);
  oled.begin();
  oled.clearDisplay();
  oled.setTextColor(WHITE, BLACK);
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
}

void loop() {
  float Tc = get_temp();
  show_temp(Tc);
  if (WiFi.status() == WL_CONNECTED) send_data(Tc);
  delay(20000);
}

float get_temp() {
  float mV = analogRead(A0)/1024.0 * 3200;      // 10 mV/°C
  return mV / 10;
}

void send_data(float Tc) {
  WiFiClient wifi;
  HTTPClient http;
  http.begin(wifi, "http://api.thingspeak.com/update");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int status = http.POST("api_key=________________&field1=" + String(Tc) + "&field2=" + WiFi.RSSI());
  http.end();
  Serial.println(status);
}

void show_temp(float Tc) {
  Serial.println(Tc);
  oled.setCursor(22, 24);
  oled.setTextSize(2);
  oled.print(Tc);
  oled.print(" C");
  oled.display();
}
```
