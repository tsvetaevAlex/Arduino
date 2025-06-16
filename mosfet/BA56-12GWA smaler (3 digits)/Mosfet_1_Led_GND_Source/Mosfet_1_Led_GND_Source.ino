/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int Gate1 = 12;
int Gate2 = 9;
int Gate3 = 8;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 4;
int led7 = 7;
int led10 = 10;
int led11 = 11;



int pause = 500;

void setup()  {
  // устанваливаем пин 9 в режим выхода
  pinMode(Gate1, OUTPUT);
  pinMode(Gate2, OUTPUT);
  pinMode(Gate3, OUTPUT);
  pinMode(led1, OUTPUT); //pin d2
  pinMode(led2, OUTPUT); //pin d3
  pinMode(led3, OUTPUT); // pin d4
  pinMode(led4, OUTPUT); //pin d5
  pinMode(led5, OUTPUT);
  pinMode(led7, OUTPUT); // pin d7
  pinMode(led10, OUTPUT); //pin d10
  pinMode(led11, OUTPUT); //pin d11
}
 

void loop() {
  digitalWrite(Gate1, HIGH );
  digitalWrite(led4, HIGH );
  digitalWrite(led7, HIGH );
  delay(pause);
  digitalWrite(Gate1, LOW );
  digitalWrite(led4, LOW );
  digitalWrite(led7, LOW );
  delay(pause);
  digitalWrite(Gate2, HIGH );
  digitalWrite(led4, HIGH );
  digitalWrite(led7, HIGH );
  delay(pause);
  digitalWrite(Gate2, LOW );
  digitalWrite(led4, LOW );
  digitalWrite(led7, LOW );
  delay(pause);
  digitalWrite(Gate3, HIGH );
  digitalWrite(led4, HIGH );
  digitalWrite(led7, HIGH );
  delay(pause);
  digitalWrite(Gate3, LOW );
  digitalWrite(led4, LOW );
  digitalWrite(led7, LOW );
  delay(pause);
}

