#include <Wire.h>
#include <MPU6050.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(128, 32, &Wire, -1);

MPU6050 mpu;
int count = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  Wire.begin();
  mpu.initialize();
}

void loop() {
  float ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  if (az > 12) {
    count++;
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Whistle Detected!");
    display.setCursor(0,10);
    display.print("Count: ");
    display.println(count);
    display.display();
    delay(500);
  }
}
