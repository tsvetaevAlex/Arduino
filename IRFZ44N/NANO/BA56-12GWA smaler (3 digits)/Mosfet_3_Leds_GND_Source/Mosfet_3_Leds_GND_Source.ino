/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int Gate1 = 12;
int Gate2 = 9;
int Gate3 = 8;
int pause = 1;
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led7 = 7;
int led10 = 10;
int led11 = 11;


void setup()  {
  // устанваливаем пин 9 в режим выхода
  pinMode(Gate1, OUTPUT);
  pinMode(Gate2, OUTPUT);
  pinMode(Gate3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);

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
    digitalWrite(led1, HIGH );
    digitalWrite(led2, HIGH );
    digitalWrite(led5, HIGH );
    digitalWrite(led7, HIGH );
    digitalWrite(led11, HIGH );
    digitalWrite(led11, HIGH );
  
    delay(pause);
    digitalWrite(Gate2, LOW );
    digitalWrite(led1,LOW );
    digitalWrite(led2, LOW );
    digitalWrite(led5, LOW );
    digitalWrite(led7, LOW );
    digitalWrite(led11, LOW );

    delay(pause);
 
  digitalWrite(Gate3, HIGH );
  digitalWrite(led2, HIGH );
  digitalWrite(led4, HIGH );
  digitalWrite(led5, HIGH );
  digitalWrite(led7, HIGH );
  digitalWrite(led11, HIGH );
  delay(pause);

  digitalWrite(Gate3, LOW );
  digitalWrite(led2, LOW );
  digitalWrite(led4, LOW );
  digitalWrite(led5, LOW );
  digitalWrite(led7, LOW );
  digitalWrite(led11, LOW );
  delay(pause);
} // rnd of loop
