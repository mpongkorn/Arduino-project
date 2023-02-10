const int LED_PIN = 7;
const int BUTTON_PIN = 8;
const int DELAY_US = 500;
const int OFF_DELAY_MS = 10000;

unsigned long timer = 0;
int buttonState = 0;
int ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  timer++;
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    timer = 0;
  }
  else if (buttonState == LOW && timer >= OFF_DELAY_MS) {
    digitalWrite(LED_PIN, LOW);
    timer = 0;
  }

  delayMicroseconds(DELAY_US);
}
