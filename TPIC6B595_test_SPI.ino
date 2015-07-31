#include <SPI.h>


/*
 * See http://forum.arduino.cc/index.php?topic=167887.0
 *
 * Current reading for 12 LED (10cm) is 54mA
 */
const int datapin = 11; // MOSI / ser in
const int clockpin = 13; // SPI CSLK / srck
const int latchpin = 8; // SPI SS / rck

void setup() {
  // Set the three SPI pins to be outputs:
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
  SPI.begin();
}

void loop() {
  digitalWrite(latchpin, LOW);
  SPI.transfer(B11111111);
  digitalWrite(latchpin, HIGH);

  delay(1000);

  digitalWrite(latchpin, LOW);
  SPI.transfer(B0000000);
  digitalWrite(latchpin, HIGH);
  delay(1000);
}
