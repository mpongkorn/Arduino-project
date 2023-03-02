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
float energy_1 = 0;
float power_1 = 0, max_power = 0;
int voltage1_len = 0, current1_len = 0, power_len = 0, energy_len = 0;
int Cursor_index_Time = 0, Cursor_index_v1 = 0, Cursor_index_c1 = 0, Cursor_index_p = 0, Cursor_index_e = 0;
const int chipSelect = 4;
File dataFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  lcd.begin();
  lcd.noBacklight();   // ปิด backlight
  //  lcd.backlight();       // เปิด backlight
  pinMode(7, OUTPUT);
  pinMode(SS, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("0000");
  lcd.setCursor(5, 0);
  lcd.print("000V");
  lcd.setCursor(11, 0);
  lcd.print("0000A");
  lcd.setCursor(0, 1);
  lcd.print("000kW");
  lcd.setCursor(6, 1);
  lcd.print("00000000Wh");

  //-------------------SD Card module Set up Begin-----------------//
  if (!SD.begin(chipSelect)) {
    while (1) ;
  }
  dataFile = SD.open("datalog2.txt", FILE_WRITE); // change new file
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
    voltage1 = sensorVoltage1 * (660.0 / 1023.0);
    //    Serial.println(sensorVoltage1);
    int sensorCurrent1 = analogRead(A1);
    Serial.println(sensorCurrent1);
    current1 = 2.0105 * sensorCurrent1 - 1244.5;  // For CURRENT SENSOR 1
    //    current1 = 2.0212 * sensorCurrent1 - 1281.4; // For CURRENT SENSOR 2
    //    current1 = 2.0351 * sensorCurrent1 - 1245.1;  // For CURRENT SENSOR 3



    //    current1 = 400 * sensorCurrent1 * (800.0 / 1023.0) - 1200.0;
    voltage1 = constrain(voltage1, 0, 660);
    current1 = constrain(current1, -800, 800);

    power_1 = (voltage1 * current1 / 1000);
    energy_1 = energy_1 + ((power_1 * interval_energy) / 3600);
    if (power_1 > max_power) {
      max_power = power_1;
    }

    dataFile.print(time_SD);
    dataFile.print(' ');
    dataFile.print(voltage1);
    dataFile.print(' ');
    dataFile.print(current1);
    dataFile.print(' ');
    dataFile.println(power_1);
    dataFile.flush();
    time_SD = time_SD + 0.25;

    // -------------------------------------------READ END--------------------------------------


    // -------------------------------------------LCD START--------------------------------------
    // ----------------LCD HV VOLTAGE---------------------
    voltage1_len = String(voltage1).length();
    Cursor_index_v1 = 11 - voltage1_len;
    lcd.setCursor(4, 0);
    lcd.print("    ");
    lcd.setCursor(Cursor_index_v1, 0);
    lcd.print(voltage1, 0);

    lcd.setCursor(10, 0);
    lcd.print(" ");

    // ----------------LCD HV CURRENT---------------------
    current1_len = String(current1).length();
    Cursor_index_c1 = 18 - current1_len;
    lcd.setCursor(11, 0);
    lcd.print("    ");
    lcd.setCursor(Cursor_index_c1, 0);
    lcd.print(current1, 0);



    // ----------------LCD Power---------------------
    power_len = String(max_power).length();
    Cursor_index_p = 6 - power_len;
    lcd.setCursor(0, 1);
    lcd.print("   ");

    lcd.setCursor(Cursor_index_p, 1);
    lcd.print(max_power, 0);


    lcd.setCursor(5, 1);
    lcd.print(" ");
    // ----------------LCD Energy---------------------

    energy_len = String(energy_1).length();
    Cursor_index_e = 15 - energy_len;
    lcd.setCursor(6, 1);
    lcd.print("        ");
    lcd.setCursor(Cursor_index_e, 1);
    lcd.print(energy_1, 1);


    // -------------------------------------------LCD END--------------------------------------
    //    FOR DEBUG
    //            Serial.println(current1/46);
    //
    //            Serial.print("V: ");
    //            Serial.print(voltage1);
    //            Serial.print("I: ");
    //            Serial.print(current1);
    //            Serial.print("P: ");
    //            Serial.print(max_power);
    //            Serial.print("E: ");
    //            Serial.println(energy_1);
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
    lcd.setCursor(4, 0);
    lcd.print(" ");
  }
}
