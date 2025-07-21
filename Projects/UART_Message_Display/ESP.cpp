#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define RXD2 19
#define TXD2 18

void setup() {
  Serial.begin(115200);          // For debug
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);  // UART to RPi

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 init failed"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Waiting for RPi...");
  display.display();
}

void loop() {
  if (Serial2.available()) {
    String incoming = Serial2.readStringUntil('\n');
    Serial.println("Received: " + incoming);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("From RPi:");
    display.println("\n" + incoming);
    display.display();
  }
}
