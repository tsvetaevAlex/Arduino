/*
включение последовательно 4 светодиодовв
все 4 светодиода постоянно подключены к общей шине питания.
светодиод включается подключением к нему GND. через н мосфет(полевой транзистор)
управление влючением светодиодов не включением и выключением питания, а подключением и отключением GND.
 */
int Gate1 = 1;
int Gate2 = 2;
int Gate3 = 3;
int Gate4 = 4;
int pause = 50;


void setup()  {
  pinMode(Gate1, OUTPUT);
  pinMode(Gate2, OUTPUT);
  pinMode(Gate3, OUTPUT);
  pinMode(Gate4, OUTPUT);
}
 
void loop() {
    digitalWrite(Gate1, HIGH );
    delay(pause);
  
    digitalWrite(Gate1, LOW );
    delay(pause);

    digitalWrite(Gate2, HIGH );
    delay(pause);
    digitalWrite(Gate2, LOW );
    delay(pause);
 
  digitalWrite(Gate3, HIGH );
  delay(pause);
  digitalWrite(Gate3, LOW );
  delay(pause);

  digitalWrite(Gate4, HIGH );
  delay(pause);
  digitalWrite(Gate4, LOW );
  delay(pause);
} // rnd of loop
