#include "max6675.h"

//Thermocouple 1
int thermo1DO = 2;
int thermo1CS = 3;
int thermo1CLK = 4;
MAX6675 thermocouple1(thermo1CLK, thermo1CS, thermo1DO);

//Thermocouple 2
int thermo2DO = 5;
int thermo2CS = 6;
int thermo2CLK = 7;
MAX6675 thermocouple2(thermo2CLK, thermo2CS, thermo2DO);

//Thermocouple 3
int thermo3DO = 8;
int thermo3CS = 9;
int thermo3CLK = 10;
MAX6675 thermocouple3(thermo3CLK, thermo3CS, thermo3DO);

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {    
  int sensorValue3 = analogRead(A3); // Voltage positive
  
  //String teststr = Serial.readString();  //read until timeout
  int teststr = Serial.read();  //read until timeout
  //teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == 49) {            //read 1 = 49   
    digitalWrite(12, LOW);  
    Serial.print(thermocouple1.readCelsius());
    Serial.print(" ");
    Serial.print(thermocouple2.readCelsius());
    Serial.print(" ");
    Serial.print(thermocouple3.readCelsius());
    Serial.print(" ");
    Serial.println(sensorValue3);
  } else if (teststr == 50){     //read 2 = 50   
    digitalWrite(12, HIGH);
    Serial.print(thermocouple1.readCelsius());
    Serial.print(" ");
    Serial.print(thermocouple2.readCelsius());
    Serial.print(" ");
    Serial.print(thermocouple3.readCelsius());
    Serial.print(" ");
    Serial.println(sensorValue3);
  }
   else{
    digitalWrite(2, LOW);
    Serial.println("000 000 000 000");
    }
    }
}
