#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long previousMillis = 0;
unsigned long previousMillis_energy = 0;
const long interval_lcd = 1000;
const long interval_energy = 250;
float sec = 0, time_SD = 0;
int currentMillis_len = 0, Cursor_index_currentMillis = 0;
float voltage1 = 0, current1 = 0;
int voltage2 = 0, current2 = 0;
float power = 0, power1 = 0, power2 = 0;
int voltage1_len = 0, current1_len = 0, voltage2_len = 0, current2_len = 0, power_len = 0;
int Cursor_index_Time = 0, Cursor_index_v1 = 0, Cursor_index_v2 = 0, Cursor_index_c1 = 0, Cursor_index_c2 = 0, Cursor_index_p = 0;
const int chipSelect = 10;
File dataFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  lcd.begin();
  //lcd.noBacklight();   // ปิด backlight
  lcd.backlight();       // เปิด backlight
  pinMode(7, OUTPUT);
  pinMode(SS, OUTPUT);
  lcd.print("0000");
  lcd.setCursor(5, 0);
  lcd.print("000.0");
  lcd.setCursor(11, 0);
  lcd.print("000.0");
  lcd.setCursor(0, 1);
  lcd.print("00");
  lcd.setCursor(3, 1);
  lcd.print("00");
  lcd.setCursor(6, 1);
  lcd.print("00000000.0");

  //-------------------SD Card module Set up Begin-----------------//
  if (!SD.begin(chipSelect)) {
    while (1) ;
  }
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (! dataFile) {
    while (1) ;
  }

  //-------------------SD Card module Set up End------------------//
}


void loop() {


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_energy >= interval_energy) {
    // -------------------------------------------READ START--------------------------------------
    previousMillis_energy = currentMillis;
//    digitalWrite(7, !digitalRead(7)); 
    int sensorVoltage1 = analogRead(A0);
    voltage1 = sensorVoltage1 * (600.0 / 1023.0);
    int sensorCurrent1 = analogRead(A1);
    current1 = sensorCurrent1 * (120.0 / 1023.0);
    int sensorVoltage2 = analogRead(A2);
    voltage2 = sensorVoltage2 * (100 / 1023.0);
    int sensorCurrent2 = analogRead(A3);
    current2 = sensorCurrent2 * (12 / 1023.0);
    power1 = power1 + (voltage1 * current1 * interval_energy / 1000);
    power2 = power2 + (voltage2 * current2 * interval_energy / 1000);
    power = (power1 + power2) / 3600;

    dataFile.print(time_SD);
    dataFile.print(' ');
    dataFile.print(voltage1);
    dataFile.print(' ');
    dataFile.print(current1);
    dataFile.print(' ');
    dataFile.print(voltage2);
    dataFile.print(' ');
    dataFile.print(current2);
    dataFile.print(' ');
    dataFile.println(power);
    dataFile.flush();
    time_SD = time_SD + 0.25;

    // -------------------------------------------READ END--------------------------------------


    // -------------------------------------------LCD START--------------------------------------
    // ----------------LCD HV VOLTAGE---------------------
    voltage1_len = String(voltage1).length();
    Cursor_index_v1 = 11 - voltage1_len;
    if (voltage1 > 0) {
      lcd.setCursor(Cursor_index_v1, 0);
      lcd.print(voltage1, 1);
    }
    else {
      lcd.setCursor(5, 0);
      lcd.print("  ");
      lcd.setCursor(7, 0);
      lcd.print("0.0");
    }
    lcd.setCursor(10, 0);
    lcd.print(" ");

    // ----------------LCD HV CURRENT---------------------
    current1_len = String(current1).length();
    Cursor_index_c1 = 17 - current1_len;
    if (current1 > 0) {
      lcd.setCursor(Cursor_index_c1, 0);
      lcd.print(current1, 1);
    }
    else {
      lcd.setCursor(11, 0);
      lcd.print("  ");
      lcd.setCursor(13, 0);
      lcd.print("0.0");
    }

    // ----------------LCD LV VOLTAGE---------------------
    voltage2_len = String(voltage2).length();
    Cursor_index_v2 = 2 - voltage2_len;
    if (voltage2 > 0) {
      lcd.setCursor(Cursor_index_v2, 1);
      lcd.print(voltage2);
    }
    else {
      lcd.setCursor(0, 1);
      lcd.print("00");
    }

    // ----------------LCD LV VOLTAGE---------------------
    current2_len = String(current2).length();
    Cursor_index_c2 = 5 - current2_len;

    if (current2 > 0) {
      lcd.setCursor(Cursor_index_c2, 1);
      lcd.print(current2);
    }
    else {
      lcd.setCursor(3, 1);
      lcd.print("00");
    }

    // ----------------LCD POWER---------------------

    power_len = String(power).length();
    Cursor_index_p = 17 - power_len;
    if (power > 0) {
      lcd.setCursor(Cursor_index_p, 1);
      lcd.print(power, 1);
    }
    else {
      lcd.setCursor(6, 1);
      lcd.print("       ");
      lcd.setCursor(13, 1);
      lcd.print("0.0");
    }
    // -------------------------------------------LCD END--------------------------------------
//    digitalWrite(7, !digitalRead(7));
    //    Serial.println(power);
  }

  // --- Time ----------------------------------------------------------------------
  currentMillis = millis();
  currentMillis_len = String(currentMillis).length();
  Cursor_index_currentMillis = 7 - currentMillis_len;

  if (currentMillis - previousMillis >= interval_lcd) {
    previousMillis = currentMillis;
    sec = (currentMillis / 1000);

    lcd.setCursor(Cursor_index_currentMillis, 0);
    if (currentMillis_len == 4) {
      lcd.setCursor(Cursor_index_currentMillis - 1, 0);
    }
    if (currentMillis_len < 5) {
      lcd.print("0");
    }
    lcd.print(sec, 0);
  }
}

