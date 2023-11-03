#define led1 12
#define led2 11
#define led3 10
#define led4 9

#define button1 8
#define button2 7
#define button3 6
#define button4 5

#define button_main 4

byte butt1;
byte butt2;
byte butt3;
byte butt4;

byte flag = 0;
int count = 0;
int count1 = 0;
int count2 = 0;
boolean good_flag = 0;
unsigned long timerForReset = 0;
unsigned long lastpr = 0;
unsigned long lastprs = 0;
void proverka() {
  for (int a = 9; a <= 12; a++) {
    digitalWrite(a, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    delay(100);
  }
  for (int a = 12; a >= 9; a--) {
    digitalWrite(a, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    delay(100);
  }
  digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); delay(130);
  digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW); digitalWrite(led4, LOW); delay(130);
  digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); delay(130);
  digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW); digitalWrite(led4, LOW); delay(130);
  digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); delay(130);
  digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW); digitalWrite(led4, LOW); delay(130);
  digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); delay(130);
  digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW); digitalWrite(led4, LOW); delay(130);
}
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(button_main, INPUT_PULLUP);

  proverka();
}

void loop() {
  butt1 = !digitalRead(button1);
  butt2 = !digitalRead(button2);
  butt3 = !digitalRead(button3);
  butt4 = !digitalRead(button4);
  byte butt_main = !digitalRead(button_main);

  if (butt1 == 1 && flag == 0) {
    flag = 1; 
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(150);

    digitalWrite(led1, HIGH);
    delay(150);
    digitalWrite(led1, LOW);
    delay(150);
    digitalWrite(led1, HIGH);
    delay(150);
    digitalWrite(led1, LOW);
    delay(150);
    digitalWrite(led1, HIGH);
  }
  if (butt2 == 1 && flag == 0){ 
    flag = 1;
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
    delay(150);

    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led2, LOW);
    delay(150);
    digitalWrite(led2, HIGH);
    delay(150);
    digitalWrite(led2, LOW);
    delay(150);
    digitalWrite(led2, HIGH);
  }

  if (butt3 == 1 && flag == 0) {
    flag = 1; 
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led3, LOW);
    delay(150);

    digitalWrite(led3, HIGH);
    delay(150);
    digitalWrite(led3, LOW);
    delay(150);
    digitalWrite(led3, HIGH);
    delay(150);
    digitalWrite(led3, LOW);
    delay(150);
    digitalWrite(led3, HIGH);
  }

  if (butt4 == 1 && flag == 0){
    flag = 1; 
    digitalWrite(led4, HIGH);
    delay(1000);
    digitalWrite(led4, LOW);
    delay(150);

    digitalWrite(led4, HIGH);
    delay(150);
    digitalWrite(led4, LOW);
    delay(150);
    digitalWrite(led4, HIGH);
    delay(150);
    digitalWrite(led4, LOW);
    delay(150);
    digitalWrite(led4, HIGH);
  }

  if (butt_main == 1 && flag == 1 && good_flag == 0) {
    count++;
    delay(1);
  }
  if (butt_main == 0) {
    count = 0; 
    count1 = 0; 
    count2 = 0;
  }
  if (count == 60 ) {
    flag = 0;
    for (byte i = 9; i <= 12; i++) {
      digitalWrite(i, LOW);
    }
    count = 0;
  }

  if (butt_main == 1 && good_flag == 0) {
    count1++;
    delay(1);
  }

  if (count1 == 1050) {
    good_flag = 1;
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, HIGH);
      delay(300);
    }
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, LOW);
    }
    delay(100);
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, HIGH);
    }
    delay(100);
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, LOW);
    }     
    flag = 2;    
    count1 = 0;   
  }

  if (flag == 2) testing();

  if (butt_main == 1 && good_flag == 1 && flag == 2) {
    count2++;
    delay(1);
  }
  if (count2 == 1050) {
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, HIGH);
      delay(300);
    }
    for (int d = 9; d <=12; d++) {
      digitalWrite(d, LOW);
    }
    flag = 0;
    good_flag = 0;
    count2 = 0;
  }
}
/*int blinking(int led) {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(150);

  digitalWrite(led, HIGH);
  delay(150);
  digitalWrite(led, LOW);
  delay(150);
  digitalWrite(led, HIGH);
  delay(150);
  digitalWrite(led, LOW);
  delay(150);
  digitalWrite(led, HIGH);
}*/
void testing() {
  if (butt1 == 1) digitalWrite(led1, HIGH);
  if (butt1 == 0) digitalWrite(led1, LOW);
  if (butt2 == 1) digitalWrite(led2, HIGH);
  if (butt2 == 0) digitalWrite(led2, LOW);
  if (butt3 == 1) digitalWrite(led3, HIGH);
  if (butt3 == 0) digitalWrite(led3, LOW);
  if (butt4 == 1) digitalWrite(led4, HIGH);
  if (butt4 == 0) digitalWrite(led4, LOW);
}

