/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int Gate1 = 1;
int Gate2 = 2;
int Gate3 = 3;
int pause = 250;


void setup()  {
  // устанваливаем пин 9 в режим выхода
  pinMode(Gate1, OUTPUT);
  pinMode(Gate2, OUTPUT);
  pinMode(Gate3, OUTPUT);

}
 

void loop() {
  digitalWrite(Gate1, HIGH );
  delay(pause);
  digitalWrite(Gate1, LOW );
  //delay(pause);
  digitalWrite(Gate2, HIGH );
  delay(pause);
  digitalWrite(Gate2, LOW );
  //delay(pause);
  digitalWrite(Gate3, HIGH );
  delay(pause);
  digitalWrite(Gate3, LOW );
  delay(pause);
}

