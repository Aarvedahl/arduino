/* 
 *  Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
 */

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  leds = 0;
  updateShiftRegister();
  delay(100);
    for (int i = 8; i>=0; i--) {
      bitSet(leds, i);
      updateShiftRegister();
      delay(100);
      bitClear(leds, 0);
      updateShiftRegister();
      delay(100);
    }
 
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

