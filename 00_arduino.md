# Arduino

## Instalasi

Panduan instalasi untuk Linux <https://www.arduino.cc/en/Guide/Linux>
atau Windows <https://www.arduino.cc/en/Guide/Windows>.

Jika port serial tidak dikenali pada Linux, tambahkan *user* ke grup
`dialout` dengan perintah berikut, lalu logout.

`sudo adduser $USER dialout`

## Setting *board* selain Uno

### Arduino Nano

- *Tools -> Board -> Arduino Nano*
- *Tools -> Processer -> ATmega328P (Old Bootloader)*
- *Tools -> Serial Port -> /dev/ttyUSB0*

### Wemos D1 mini (ESP8266)

- *File -> Preferences -> Additional Board ->* <https://arduino.esp8266.com/stable/package_esp8266com_index.json>
- *Tools -> Board -> Board Managers -> esp8266 -> Install*
- *Tools -> Board -> LOLIN(WEMOS) D1 R2 & mini*
- *Tools -> Serial Port -> /dev/ttyUSB0*

## Referensi bahasa pemrograman

<https://www.arduino.cc/reference>

## Pinout Uno

![Arduino Uno](datasheet/Pinout Uno R3.png)
