//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  initChars();
  drawColons();
}


void loop() {

  uint32_t sec = millis() * 3600 / 1000ul;
  int seconds = (sec % 3600ul) % 60ul;
  int minutes = (sec % 3600ul) / 60ul;
  int hours = (sec / 3600ul) % 24ul;
  drawDigit(hours / 10, 0);
  drawDigit(hours % 10, 3);
  drawDigit(minutes / 10, 7);
  drawDigit(minutes % 10, 10);
  drawDigit(seconds / 10, 14);
  drawDigit(seconds % 10, 17);
  delay(300);
}

void initChars() {
  byte customCharFull[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };

  byte customCharTop[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000
  };

  byte customCharBottom[] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111
  };

  byte customCharLeft[] = {
    B00111,
    B00111,
    B00111,
    B00111,
    B00111,
    B00111,
    B00111,
    B00111
  };

  byte customCharRight[] = {
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100
  };

  byte customCharBottomLeft[] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B11100,
    B11100,
    B11100,
    B11100
  };

  byte customCharBottomRight[] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00111,
    B00111,
    B00111,
    B00111
  };

  byte customCharTopLeft[] = {
    B11100,
    B11100,
    B11100,
    B11100,
    B00000,
    B00000,
    B00000,
    B00000
  };

  byte customCharTopRight[] = {
    B00111,
    B00111,
    B00111,
    B00111,
    B00000,
    B00000,
    B00000,
    B00000
  };

  lcd.createChar(0, customCharFull);
  lcd.createChar(1, customCharTop);
  lcd.createChar(2, customCharBottom);
  lcd.createChar(3, customCharLeft);
  lcd.createChar(4, customCharRight);
  lcd.createChar(5, customCharBottomLeft);
  lcd.createChar(6, customCharTopLeft);
  lcd.createChar(7, customCharTopRight);
}

void drawColons() {
  lcd.setCursor(6, 0);
  lcd.print(" ");
  lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.setCursor(6, 2);
  lcd.write(2);
  lcd.setCursor(6, 3);
  lcd.print(" ");

  lcd.setCursor(13, 0);
  lcd.print(" ");
  lcd.setCursor(13, 1);
  lcd.write(1);
  lcd.setCursor(13, 2);
  lcd.write(2);
  lcd.setCursor(13, 3);
  lcd.print(" ");
}

void drawDigit(uint8_t digit, uint8_t offset) {
  switch (digit) {
    case 0:
      drawZero(offset);
      break;
    case 1:
      drawOne(offset);
      break;
    case 2:
      drawTwo(offset);
      break;
    case 3:
      drawThree(offset);
      break;
    case 4:
      drawFour(offset);
      break;
    case 5:
      drawFive(offset);
      break;
    case 6:
      drawSix(offset);
      break;
    case 7:
      drawSeven(offset);
      break;
    case 8:
      drawEight(offset);
      break;
    case 9:
      drawNine(offset);
      break;
  }
}

void drawZero(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(0);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.write(3);
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(0);
  lcd.write(4);
}

void drawOne(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.print(" ");
  lcd.write(0);
  lcd.print(" ");
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.write(0);
  lcd.print(" ");
  lcd.setCursor(0 + offset, 2);
  lcd.print(" ");
  lcd.write(0);
  lcd.print(" ");
  lcd.setCursor(0 + offset, 3);
  lcd.write(2);
  lcd.write(0);
  lcd.write(2);
}

void drawTwo(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(0);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.print(" ");
  lcd.write(2);
  lcd.write(6);
  lcd.setCursor(0 + offset, 2);
  lcd.write(3);
  lcd.write(1);
  lcd.print(" ");
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(2);
  lcd.write(2);
}

void drawThree(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.print(" ");
  lcd.write(2);
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.print(" ");
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
}

void drawFour(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(4);
}

void drawFive(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(1);
  lcd.write(1);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.write(2);
  lcd.write(5);
  lcd.setCursor(0 + offset, 2);
  lcd.write(7);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(2);
  lcd.write(2);
  lcd.write(4);
}

void drawSix(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.print(" ");
  lcd.print(" ");
  lcd.setCursor(0 + offset, 2);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
}

void drawSeven(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.print(" ");
  lcd.write(0);
  lcd.print(" ");
  lcd.setCursor(0 + offset, 3);
  lcd.print(" ");
  lcd.write(0);
  lcd.print(" ");
}

void drawEight(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
}

void drawNine(uint8_t offset) {
  lcd.setCursor(0 + offset, 0);
  lcd.write(3);
  lcd.write(1);
  lcd.write(4);
  lcd.setCursor(0 + offset, 1);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
  lcd.setCursor(0 + offset, 2);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(4);
  lcd.setCursor(0 + offset, 3);
  lcd.write(3);
  lcd.write(2);
  lcd.write(4);
}
