int i;
unsigned long j = 0;
int a = 0;
int b = 0;
int k = 1;
byte value;
int pulse_pin = 21;
int output_pin = 22;
int input_pin = 35;

void setup() {
// put your setup code here, to run once:
// Serial.begin(9600);
  pinMode(pulse_pin, OUTPUT);
  pinMode(output_pin, OUTPUT);
  pinMode(input_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = i + 1;
  j = j + 1;
  if (i <= 68) {
    if (k == 1) {
      digitalWrite(pulse_pin, HIGH);
      k = 0;
    }
    else {
      digitalWrite(pulse_pin, LOW);
      k = 1;
    }
  }
  if (i > 68 && i < 73) {
    digitalWrite(pulse_pin, LOW);
    if (i == 72) {
      i = 0;
    }
  }
  //

  value = digitalRead(input_pin);
  if (value == 0) {
    digitalWrite(output_pin, HIGH);
    a = 0;
  }
  if (value == 1) {
    //    delay 10 seconds before digitalWrite LOW
    if (a == 0) {
      j = 0;
      a = 1;
    }
    if ( a == 1 && j >= 20000) {
      digitalWrite(output_pin, LOW);
      a = 0;
    }
  }
  delayMicroseconds(500);
}



