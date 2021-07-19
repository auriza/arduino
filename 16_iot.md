# 16. IoT temperature sensor

![](gfx/16_iot.png)

- Wemos D1 mini
- OLED 128x64 SSD1306
- LM35
- ThingSpeak API

```ino
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SSID  "CB-06"
#define PASS  "1sampai10"
#define KEY   "XXXXXX"

Adafruit_SSD1306 oled(-1);

void setup() {
  Serial.begin(115200);
  oled.begin();
  oled.setTextColor(WHITE);
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
}

void loop() {
  float Tc = get_temp();
  show_temp(Tc);
  if (WiFi.status() == WL_CONNECTED)
    send_data(Tc);
  delay(20000);
}

float get_temp() {
  float mV = analogRead(A0)/1024.0 * 3300;          // 10 mV/°C
  return mV / 10;
}

void send_data(float Tc) {
  WiFiClient wifi;
  HTTPClient http;
  http.begin(wifi, "http://api.thingspeak.com/update");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int status = http.POST("api_key=KEY&field1=" + String(Tc) + "&field2=" + WiFi.RSSI());
  http.end();
  Serial.println(status);
}

void show_temp(float Tc) {
  Serial.println(Tc);
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextSize(2);
  oled.print(Tc, 1);
  oled.print("'C");
  oled.display();
}
