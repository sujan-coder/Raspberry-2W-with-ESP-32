# Raspberry Pi to ESP32 UART Communication with OLED Display

This project demonstrates UART communication between a Raspberry Pi and an ESP32. The ESP32 receives messages via UART from the Raspberry Pi and displays them on an I2C OLED screen.

## Features

- UART communication between Raspberry Pi and ESP32
- Messages typed on Raspberry Pi are displayed on ESP32's OLED
- OLED display: 128x64 SSD1306 (I2C)

## Hardware Used

- **Raspberry Pi Zero 2W** 
- **ESP32 Dev Board**
- **OLED Display** (SSD1306, 128x64, I2C)

## Wiring

| Raspberry Pi GPIO | ESP32 Pin | Function  |
|-------------------|-----------|-----------|
| GPIO14 (TXD)      | GPIO5     | ESP32 RX  |
| GPIO15 (RXD)      | GPIO4     | ESP32 TX  |
| GND               | GND       | Ground    |
|                   | GPIO18    | OLED SCL  |
|                   | GPIO19    | OLED SDA  |

> 📌 Make sure to cross TX ↔ RX and connect GNDs.

## ESP32 Arduino Code

The ESP32 initializes Serial2 (custom UART) on GPIO4/5 and displays received messages on the OLED.

Libraries used:
- `Adafruit_GFX`
- `Adafruit_SSD1306`
- `Wire`

Install via PlatformIO:
```ini
lib_deps =
  adafruit/Adafruit GFX Library@^1.12.1
  adafruit/Adafruit SSD1306@^2.5.15

