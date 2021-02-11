#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define PHOTOSENSOR 2

void setup() {
  pinMode(PHOTOSENSOR, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" Photo  Interrupter");
}

void loop() {
  lcd.setCursor(0, 2);
  if (digitalRead(PHOTOSENSOR)) {
    lcd.print("*****BLOCKED*****");
  } else {
    lcd.print("                  ");
  }
}
