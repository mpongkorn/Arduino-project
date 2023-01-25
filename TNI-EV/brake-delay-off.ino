int i;
unsigned long j = 0;
int a = 0;
int b = 0;
int k = 1;
byte value;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  j = j + 1;
  value = digitalRead(8);
  if (value == 1) {
    digitalWrite(7, HIGH);
    a = 0;
  }
  if (value == 0) {
    //    delay 10 seconds before digitalWrite LOW
    if (a == 0) {
      j = 0;
      a = 1;
    }
    if ( a == 1 && j >= 6000) {
      digitalWrite(7, LOW);
      a = 0;
    }
  }
  delayMicroseconds(500);
}




