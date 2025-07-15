int latchPin = 4;  // STCP
int clockPin = 3;  // SHCP
int dataPin  = 2;  // DS

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Пример: включение всех светодиодов
  byte leds = B11111111;  // все включены
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(500);

  // Все выключить
  leds = B00000000;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(500);
}
