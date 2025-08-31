/*
 Пример управления яркостью светодиода
 на выходе контроллера Arduino.
 Управление 7-сегментным индикатором SC10-21SRWA.
*/

int GateUpper = 9;
int GateLower = 8;
int const pinsQTY = 11;

// Пины для сегментов
int led1  = 1;  // lower left segment
int led2  = 2;  // lower middle segment
int led3  = 3;  // dot (если нужен)
int led4  = 4;  // center segment
int led5  = 5;  // lower right segment
int led7  = 7;  // upper right segment
int led10 = 10; // upper left segment
int led11 = 11; // upper middle segment
int pinMaxNumber = 11;
int pause = 500;
int currentDigit = 0;
int freezePause = 1500;

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

void setup() {
  Serial.begin(9600);

  pinMode(GateLower, OUTPUT);
  pinMode(GateUpper, OUTPUT);

  // Устанавливаем режим OUTPUT для всех сегментов
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void showDigit(int digit) {
  if (digit < 0 || digit > 9) return;

  Serial.println("------> Show digit Begin");
  Serial.println("Digit received: " + String(digit));

  int* segments = digits[digit];

  // ----------------- Gate Upper ------------------
  digitalWrite(GateUpper, HIGH);
  for (int i = 0; i < 8; i++) {
    if (segments[i]) {
      digitalWrite(segmentPins[i], HIGH);
      Serial.println("Segment ON (Upper): " + String(i));
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }
  delay(pause);
  digitalWrite(GateUpper, LOW);

  // ----------------- Gate Lower ------------------
  digitalWrite(GateLower, HIGH);
  for (int i = 0; i < 8; i++) {
    if (segments[i]) {
      digitalWrite(segmentPins[i], HIGH);
      Serial.println("Segment ON (Lower): " + String(i));
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }
  delay(pause);
  digitalWrite(GateLower, LOW);

  Serial.println("------> Show digit End\n");
}

  void loop() {

    int* segments = digits[currentDigit];
    {
      showDigit(currentDigit);
      delay(1000);
      if (currentDigit >= 9)
      {
      currentDigit = 0; 
      }
      // ----------------- Begin of Upper Gate------------------
      digitalWrite(GateUpper, HIGH);

      for (int j =1; j<=pinMaxNumber; ++j)
      {
        if (segments[j]) {
          digitalWrite(segmentPins[j], HIGH);
          Serial.println("Segment ON (Upper): " + String(j));
        } else {
          digitalWrite(segmentPins[j], LOW);
        }
      }
      digitalWrite(GateUpper, LOW);
      // ----------------- End  of Upper Gate------------------
      // ----------------- Begin of Lower Gate------------------
      digitalWrite(GateLower, HIGH);

      for (int j =1; j<=pinsQTY; ++j)
      {
        if (segments[j]) {
          digitalWrite(segmentPins[j], HIGH);
          Serial.println("Segment ON (Upper): " + String(j));
        } else {
          digitalWrite(segmentPins[j], LOW);
        }
      }
      digitalWrite(GateLower, LOW);
      // ----------------- End  of Lower Gate------------------
      delay(freezePause); // to leep shown digit for a few momrnts

      // end of main Loop itteration, show 1 ddigit;
      ++currentDigit; //sry to next difit for next itteration.
    } // end of int* segments = digits[digit];

  } //end of loop()