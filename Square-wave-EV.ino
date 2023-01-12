// Square wave 34 loop + 50% duty cycle PWM 2 loop
void setup()
{
  //  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop()
{
  for (int i = 1; i < 35; i++) {
    digitalWrite(5, HIGH);
    delayMicroseconds(300); // Approximately 10% duty cycle @ 1KHz
    digitalWrite(5, LOW);
    delayMicroseconds(300);
    //    Serial.print("--------------------------------------- ");
    //    Serial.println(i);
  }
  for (int i = 1; i < 3; i++) {
    digitalWrite(5, LOW);
    delayMicroseconds(300 * 2);
    //    Serial.println("---------------------------------------END loop");
  }
}
