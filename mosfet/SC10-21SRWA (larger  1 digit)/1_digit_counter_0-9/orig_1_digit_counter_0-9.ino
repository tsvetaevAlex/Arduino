/*
 Пример управления яркостью светодиода
 на выходе 9 контроллера Arduino
 функцией analogWrite().
 */
int GateUpper = 9;
int GateLower = 8;
int led1 = 1; // lower left  segment
int led2 = 2; // lower middle segment
int led3 = 3; //dot
int led4 = 4; // middle center segment
int led5 = 5; // loer right segment
int led7 = 7; // upper right segment
int led10 = 10; // upper left segment
int led11 = 11; // upper midddle segment
int shortDelay = 1;
int longDelay = 500;
int segments_QTY =8;

int digits[10][8] = {
  // list of segments for each digit. digit are equal to index in digits array (zero 'lrmrnt if digit 0, 1 elemet of array is digit 1,etc.)
  /*
  мтарица сегментов. каждый из массивов это набор сегментов для включения, чтобы покзать цифру. индекс массива соответсвует отображаеморй цифре  элемент [0]-цифра 0; елемент [1] цифра 1 и т.д.
  каждый из вложенных массивов это список сегментов. 0 сегмент выключен 1 сегмент включен. номер элемента в массиве соответвует номеру сегмента.
  сегменты для цифрового индикатора SC10-21SRWA, 1 разряд большого размера.
  **/
(1,	1, 0,	1,	0,	0,	1,	0,	0,	1,	1),//digit 0
(0,	0, 0,	1,  0,	0,	1,	0,	0,	0,	0),//digit 1
(1,	1, 0,	0,  1,	0,	1,	0,	0,	0,	1),//digit 2
(0,	1, 0,	1,  1,	0,	1,	0,	0,	0,	1),//digit 3
(0,	0, 0,	1,  1,	0,	1,	0,	0,	1,	1),//digit 4
(0,	1, 0,	1,  1,	0,	0,	0,	0,	1,	1),//digit 5
(0,	1, 1,	1,	1,	0,	0,	0,	0,	0,	0),//digit 6
(0,	0, 0,	1,	0,	0,	1,	0,	0,	0,	1),//digit 7
(1,	1, 0,	1,	1,	0,	1,	0,	0,	1,	1),//digit 8
(0,	1, 1,	1,	1,	0,	1,	0,	0,	1,	1)//digit 9
};

int pause = 500;

void setup()  {
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
 


void showDigit (int digit)
{
  Serial.println("------>Show digit Begin");  
  Serial.println("digit received: " + digit);
  Serial.println("digit segments:");
int GIgit_segments = digits[digit];
//Begin of --------------------------GateUpper--------------------------
digitalWrite(GateUpper, HIGH ); //Upper GATE

  for (int i; i <= segments_QTY; i++ )
    for(int i= 1; i< segments_QTY; i++ )
    {
      int is_segment_ON = GIgit_segments[i];

      if (is_segment_ON){
          Serial.println("Segment: " + i);
          digitalWrite(i, HIGH ); // activate segment
      }
      ///Endof --------------------------UpperGate--------------------------
        digitalWrite(GateUpper, LOW ); //Upper GATE
      //Begin of --------------------------GateLower--------------------------
        digitalWrite(GateLower, HIGH ); // Lower GATE
    }
    for(int i= 1;i< segments_QTY; i ++)
    {
      int is_segment_ON = GIgit_segments[i];
      if (is_segment_ON){
      
          Serial.println("Segment: " + i);
          Serial.println("Segment: " + i);
          digitalWrite(i, HIGH ); // activate segment
      }
      //End of --------------------------GateLower--------------------------
      digitalWrite(GateLower, LOW ); // LOwer GATE
    }
  {
  }


  Serial.println("------>Show digit End.");  

}


void flushIndicator()
{
  delay(200);
  for (int i =1; i <=13 ; i++)
  {
      digitalWrite(i, LOW);
  }
}


void loop ()
{
  int digits_QTY = 9;
  //
  for (int digit =0; digit <=digits_QTY; digit ++)
  {
    showDigit(digit);
    delay(1000);
  }
  }