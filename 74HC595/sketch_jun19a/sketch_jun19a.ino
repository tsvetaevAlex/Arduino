/*
 Пример управления яркостью светодиода
 на выходе контроллера Arduino.
 Управление 7-сегментным индикатором SC10-21SRWA.
*/

int const pinsQTY = 11;

// Пины для сегментов
int led1  = 1;  // lower left segment
int led2  = 2;  // lower middle segment
int led3  = 3;  // dot (если нужен)
int led4  = 4;  // center segment
int led5  = 0;  // lower right segment port forwarding to pin 6 instead of 5 because behaviour of pin 5 seems like a X_X 
int led7  = 7;  // upper right segment
int led10 = 10; // upper left segment
int led11 = 11; // upper middle segment
int pinMaxNumber = 11;
int pause = 00;
int currentDigit = 0;
int freezePause = 1500;
int itterations = 0;

// массив пинов для управления сегментами (в нужном порядке)
int segmentPins[8] = {led1, led2, led4, led5, led7, led10, led11, led3}; // led3 (точка)

// таблица сегментов для цифр 0–9 (1 = включен, 0 = выключен); pin 3 dot segment
// значение 0 элемент массива это 0 испоольтзуется дл смещения индексации. чтобы первый значимыыыыый элемент имел индекс 1.
// это сделано для того, что индекс элемента в массиве соответсвует номеру ноги на которой "висит",
// перебирая элементы массива, мы по индексу элемента, понимаем какой элемент массиса(номер ноги) в каком состоянии должен быть
int digits[10][9] = {
  //  1  2   3   4   5  7   10  11  <- segments number
  {0, 1, 1,  0,  1,  0, 1,  1,  1}, // 0
  {0, 0, 0,  0,  1,  0, 1,  0,  0}, // 1
  {0, 1, 1,  0,  0,  1, 1,  0,  1}, // 2
  {0, 0, 1,  0,  1,  0, 1,  0,  1}, // 3
  {0, 0, 0,  0,  1,  1, 1,  1,  0}, // 4
  {0, 0, 1,  0,  1,  1, 0,  1,  1}, // 5
  {0, 1, 1,  1,  1,  1, 0,  1,  1}, // 6 with dot
  {0, 0, 0,  1,  1,  0, 1,  0,  1}, // 7
  {0, 1, 1,  0,  1,  1, 1,  1,  1}, // 8
  {0, 0, 1,  1,  1,  1, 1,  1,  1}  // 9 with dot
};

void setup() 
{
  Serial.begin(9600);

  // Устанавливаем режим OUTPUT для всех сегментов
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}
void flushDisplay()
{
  for (int i = 0; i <= pinMaxNumber; i++) {
      digitalWrite(segmentPins[i], LOW);
  }
}
void showDigit(int digit) 
{
  if (digit < 0 || digit > 9) return;


  int* segments = digits[digit];

  // ----------------- Gate Upper ------------------
  for (int i = 0; i < (sizeof(segments)); i++) {
    if (segments[i]) {
      digitalWrite(segmentPins[i], HIGH);
      }
  }
  //digitalWrite(GateUpper, LOW);
  // ----------------- Gate Lower ------------------
  for (int i = 0; i < 8; i++) {
    if (segments[i]) {
      digitalWrite(segmentPins[i], HIGH);
delay (freezePause);
flushDisplay();
    } 
  }
  //digitalWrite(GateLower, LOW);
}

  void loop() {

      showDigit(currentDigit);
      ++currentDigit;
      ++ itterations;
      if (currentDigit>=9)
      {currentDigit = 0;}
      if (itterations == 10)
      {
        flushDisplay();
        exit(0);
      }
  }
  

