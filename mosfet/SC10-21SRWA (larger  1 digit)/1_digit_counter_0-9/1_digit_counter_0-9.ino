/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int GateLower = 12;
int GateUpper = 9;
int led1 = 1; // lower left  segment
int led2 = 2; // lower middle segment
int led3 = 3; //dot
int led4 = 4; // middle center segment
int led5 = 5; // loer right segment
int led7 = 7; // upper right segment
int led10 = 10; // upper left segment
int led11 = 11; // upper midddle segment
int shortDelay = 500;
int longDelay = 1000;


int digits[10][8] = {
  // list of segments for each digit. digit are equal to index in digits array (zero 'lrmrnt if digit 0, 1 elemet of array is digit 1,etc.)
  (1,2,4,7,10,11,0,0), //digit 0
  (4,7,0,0,0,0,0,0), // digit 1
  (1,2,5,7,11,0,0,0), //digit 2
  (2,4,5,7,11,0,0,0), //digit 3
  (4,7,5,10,0,0,0,0), //digit 4
  (2,4,5,10,11,0,0,0), //digit 5
  (1,2,3,4,5,10,11,0), //figit 6 with dot
  (11,4,7,0,0,0,0,0),// digit 7
  (1,2,4,5,7,10,11,0), //digit 8
  (2,3,4,5,7,10,11,0,0)//digit 9 with dot
};


int pause = 1000;

void setup()  {
  // устанваливаем пин 9 в режим выхода
  pinMode(GateLower, OUTPUT);
  pinMode(GateUpper, OUTPUT);
  pinMode(led1, OUTPUT); //pin d1
  pinMode(led2, OUTPUT); //pin d2
  pinMode(led3, OUTPUT); // pin d3
  pinMode(led4, OUTPUT); //pin d4
  pinMode(led5, OUTPUT); // pin d5
  pinMode(led7, OUTPUT); // pin d7
  pinMode(led10, OUTPUT); //pin d10
  pinMode(led11, OUTPUT); //pin d11
}
 
void loop ()
{
    digitalWrite(GateUpper, HIGH );
    delay(shortDelay);
    digitalWrite(led10, HIGH );
    delay(shortDelay);
    digitalWrite(led10, LOW );
    digitalWrite(led11, HIGH );
    delay(shortDelay);
    digitalWrite(led11, LOW );
    digitalWrite(led7, HIGH );
    delay(shortDelay);
    digitalWrite(led7, LOW );
    digitalWrite(led5, HIGH );
    digitalWrite(GateUpper, LOW );
    delay(shortDelay);
    digitalWrite(GateLower, HIGH );
    digitalWrite(led5, LOW );
    digitalWrite(led1, HIGH );
    delay(shortDelay);
    digitalWrite(led1, LOW );
    digitalWrite(led2, HIGH );
    delay(shortDelay);
    digitalWrite(led2, LOW );
    digitalWrite(led3, HIGH );
    delay(shortDelay);
    digitalWrite(led3, LOW );
    digitalWrite(led4, HIGH );
    delay(shortDelay);
    digitalWrite(led3, LOW );
    digitalWrite(led4, LOW );
    digitalWrite(GateLower, LOW);
}



