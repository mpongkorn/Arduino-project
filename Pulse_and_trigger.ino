int i;
unsigned long j = 0;
int a = 0;
int b = 0;
int k = 1;
byte value;

void setup() {
  // put your setup code here, to run once:
  //  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = i + 1;
  j = j + 1;
  if (i <= 68) {
    if (k == 1) {
      digitalWrite(5, HIGH);
      k = 0;
    }
    else {
      digitalWrite(5, LOW);
      k = 1;
    }
  }
  if (i > 68 && i < 71) {
    digitalWrite(5, LOW);
    if (i == 70) {
      i = 0;
    }
  }
  //

  value = digitalRead(8);
  if (value == 0) {
    digitalWrite(7, HIGH);
    b = 1;
    a = 0;
  }
  if (value == 1) {
    //    delay(10000);

    if ( b == 1) {
      if (a == 0) {
        j = 0;
        a = 1;
      }
      if ( a == 1 && j >= 20000) {
        digitalWrite(7, LOW);
        a = 0;
        b = 0;
      }
    }
  }
  delayMicroseconds(500);
}





