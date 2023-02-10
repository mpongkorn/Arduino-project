const int LED_PIN = 5;
const int NUM_BLINKS = 68;
const int OFF_DURATION = 5;
const int DELAY_US = 500;

int blinkCounter = 0;
bool ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  delay(2000);
}

void loop() {
  if (blinkCounter <= NUM_BLINKS) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    blinkCounter++;
  } else if (blinkCounter > NUM_BLINKS && blinkCounter < NUM_BLINKS + OFF_DURATION) {
    digitalWrite(LED_PIN, LOW);
    blinkCounter++;
  } else {
    blinkCounter = 0;
  }
  delayMicroseconds(DELAY_US);
}
