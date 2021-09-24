# 18. ESP8266 DHT11 IoT ThingSpeak

- Wemos D1 R2/mini ([setup](https://github.com/auriza/arduino/blob/main/00_arduino.md#wemos-d1-mini-esp8266))
- DHT11 temperature sensor
- LCD I2C display

```ino
/*  18. ESP8266 DHT11 IoT
    https://thingspeak.com/channels
    https://www.mathworks.com/help/thingspeak/writedata.html

    WemosD1   DHT11   LCD
    -------   -----   ---
    3V3       Vcc
    5V                Vcc
    Gnd       Gnd     Gnd
    D1                SCL
    D2                SDA
    D3        Out
 */

#include <DHT.h>                      // DHT sensor library (Adafruit)
#include <LiquidCrystal_I2C.h>        // LiquidCrystal I2C  (Marco Schwartz)
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SSID  "________"
#define PASS  "________"

DHT dht(D3, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Tc, RH;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  Tc = dht.readTemperature();
  RH = dht.readHumidity();

  show_temp();
  if (WiFi.status() == WL_CONNECTED)
    send_data();

  delay(20000);
}

void send_data() {
  WiFiClient wifi;
  HTTPClient http;
  http.begin(wifi, "http://api.thingspeak.com/update");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int status = http.POST("api_key=________&field1=" + String(Tc) + "&field2=" + RH + "&field3=" + WiFi.RSSI());
  http.end();
  lcd.setCursor(13, 1);
  lcd.print(status);
}

void show_temp() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tc     RH");
  lcd.setCursor(0, 1);
  lcd.print(Tc);
  lcd.print(char(223));
  lcd.print("    ");
  lcd.print(RH);
  lcd.print("%");
}
```
