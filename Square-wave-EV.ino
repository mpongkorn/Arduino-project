// Square wave 34 loop + 50% duty cycle
#include <Thread.h>
#include <ThreadController.h>
byte Value;

// ThreadController that will controll all threads
ThreadController controll = ThreadController();

//My Thread (as a pointer)
Thread* myThread = new Thread();
//His Thread (not pointer)
Thread hisThread = Thread();

// callback for myThread
void pulseOn() {
  for (int i = 1; i < 35; i++) {
    digitalWrite(5, HIGH);
    delayMicroseconds(500); // Approximately 10% duty cycle @ 1KHz
    digitalWrite(5, LOW);
    delayMicroseconds(500);
  }
  for (int i = 1; i < 3; i++) {
    digitalWrite(5, LOW);
    delayMicroseconds(1000);
  }
}

// callback for hisThread
void delayOff() {
  Value = map(analogRead(A1), 0, 1023, 0, 255);
  Serial.println(Value);
  if (Value >= 160) {
    digitalWrite(6, HIGH);
  }
  else {
    delay(10000);
    digitalWrite(6, LOW);
  }
}


void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  // pinMode(3, INPUT);

  // Configure myThread
  myThread->onRun(pulseOn);
  // myThread->setInterval(500);

  // Configure myThread
  hisThread.onRun(delayOff);
  // hisThread.setInterval(250);

  // Adds both threads to the controller
  controll.add(myThread);
  controll.add(&hisThread); // & to pass the pointer to it
}


void loop()
{
  controll.run();
}
