/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int ledPin = 5;
int pause = 1500;


void setup()  {
  // устанваливаем пин 9 в режим выхода
  pinMode(ledPin, OUTPUT);

}
 

void loop() {
  digitalWrite(gate, HIGH );
  delay(pause);
  digitalWrite(gate, LOW );
  delay(pause);
}

