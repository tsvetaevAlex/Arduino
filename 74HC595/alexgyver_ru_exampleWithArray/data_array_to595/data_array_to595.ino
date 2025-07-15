#define CS_595 10
#define DAT_595 11
#define CLK_595 13

void setup() {
  pinMode(CS_595, OUTPUT);
  pinMode(DAT_595, OUTPUT);
  pinMode(CLK_595, OUTPUT);

  // данные для отправки
  //bool data[] = {1, 1, 0, 0, 1, 0, 0, 1};
  bool data[] = {1, 0, 0, 0, 0, 0, 0, 0};

  digitalWrite(CS_595, LOW);    // #1

  for (int i = 0; i < sizeof(data); i++) {  // #2
    digitalWrite(DAT_595, data[i]);
    delayMicroseconds(5);
    digitalWrite(CLK_595, HIGH);
    delayMicroseconds(5);
    digitalWrite(CLK_595, LOW);
  }

  digitalWrite(CS_595, HIGH);   // #3
}

void loop() {
}