int i;
unsigned long j = 0;
int a = 0;
int b = 0;
int k = 1;
byte value;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = i + 1;
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
  if (i > 68 && i < 73) {
    digitalWrite(5, LOW);
    if (i == 72) {
      i = 0;
    }
  }
  delayMicroseconds(500);
}




