//#define BIT_ORDER LSBFIRST
#define BIT_ORDER MSBFIRST

//int resetPin = 5;  //(Master Reset зшт (ножка 10 на 595)
int latchPin = 12;  // RCLK пин защелка
int dataPin  = 14;  // SER пин данных
int syncPin = 11; // SRCLK синхронизирующий пин clockPin
int pause = 1500;
byte leds;
byte testLed = B10000000;
byte allLed =  B11111111;
const byte zeroleds = B00000000;
//byte digit1 = B10000001;
byte digit1 = B10010000; //use MSBFIRST
byte digit2 = B11110110; //use MSBFIRST
/*
void resetShiftRegister() {
  //digitalWrite(resetPin, LOW);   // активируем сброс
  delayMicroseconds(1);          // короткая задержка
  digitalWrite(resetPin, HIGH);  // возвращаем в норму
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, syncPin, BIT_ORDER, B00000000);
  digitalWrite(latchPin, HIGH);
}
*/

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(syncPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
    //leds= digit1;
  leds = B11111111; // Все включить
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, syncPin, BIT_ORDER, allLed);
  digitalWrite(latchPin, HIGH);

  // Все выключить
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, syncPin, BIT_ORDER, zeroleds);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, syncPin, MSBFIRST, digit1);
  digitalWrite(latchPin, HIGH);
 
  delay(pause);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, syncPin, MSBFIRST, zeroleds); // выключить всё
  digitalWrite(latchPin, HIGH);
  delay(10);
 }
