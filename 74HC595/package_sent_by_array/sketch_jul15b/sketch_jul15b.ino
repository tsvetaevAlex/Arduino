int latchPin = 4;  // STCP
int clockPin = 3;  // SHCP
int dataPin  = 2;  // DS
int pause = 500;
byte leds;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);f:\workspace\src\Arduino\IRFZ44N\UNO\BA56-12GWA smaler (3 digits)\UNO_Mosfet_3_digits_GND_Source_3_Digits_indicatorr\UNO_Mosfet_3_digits_GND_Source_3_Digits_indicatorr.tino

  leds = B11111111; // Все включить
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(pause);

  leds = B00000000; // Все выключить
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(pause);
}

void loop() {
  leds = B10101010; // через один (нечетные)
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds); 
  digitalWrite(latchPin, HIGH);
  delay(pause);

  leds = B00000000; // выключить
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(pause);

  leds = B01010101; // через один (четные)
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(pause);

  leds = B00000000;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(pause);
}
