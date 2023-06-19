#include <PS4Controller.h>

int RPWM_Output1 = 0;
int LPWM_Output1 = 1;
int RPWM_Output2 = 2;
int LPWM_Output2 = 3;
int RPWM_Output3 = 4;
int LPWM_Output3 = 5;
int RPWM_Output4 = 6;
int LPWM_Output4 = 7;
int PWM1 = 32;
int PWM2 = 33;
int PWM3 = 25;
int PWM4 = 26;
int PWM5 = 27;
int PWM6 = 14;
int PWM7 = 12;
int PWM8 = 13;
int RY1 = 21;
int RY2 = 19;
int RY3 = 18;
int RY4 = 4;
int RY5 = 2;

void Cross_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, HIGH);
}

void Circle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, LOW);
}

void Square_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, HIGH);
}

void Triangle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void R1Cross_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, HIGH);
}

void R1Circle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, LOW);
}

void R1Square_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, HIGH);
}

void R1Triangle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void R2Cross_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, HIGH);
}

void R2Circle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, LOW);
}

void R2Square_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, HIGH);
}

void R2Triangle_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void Share_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, HIGH);
}

void Down_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, LOW);
}

void Left_pressed() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, HIGH);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, HIGH);
}

void Right_pressed() {
  digitalWrite(RY1, HIGH);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void R2Up_pressed() {
  digitalWrite(RY1, HIGH);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, HIGH);
}

void R2Down_pressed() {
  digitalWrite(RY1, HIGH);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, LOW);
}

void R2Left_pressed() {
  digitalWrite(RY1, HIGH);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, HIGH);
  digitalWrite(RY5, HIGH);
}

void R2Right_pressed() {
  digitalWrite(RY1, HIGH);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, HIGH);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void Release() {
  digitalWrite(RY1, LOW);
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  digitalWrite(RY5, LOW);
}

void MRT1(int speed1, int speed2) {
  ledcWrite(RPWM_Output1, speed2*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, speed1);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed1);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, speed2);
  ledcWrite(LPWM_Output4, 0);
}

void MLT1(int speed3, int speed4) {
  ledcWrite(RPWM_Output1, speed3*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, speed4);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed4);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, speed3);
  ledcWrite(LPWM_Output4, 0);
}

void MRT2(int speed5, int speed6) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed6*0.95);
  ledcWrite(RPWM_Output2, speed5);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed5);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed6);
}

void MLT2(int speed7, int speed8) {
  ledcWrite(RPWM_Output1, speed7*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed8);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed8);
  ledcWrite(RPWM_Output4, speed7);
  ledcWrite(LPWM_Output4, 0);
}

void MRB1(int speed1d, int speed2d) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed1d*0.95);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed2d);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed2d);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed1d);
}

void MLB1(int speed3d, int speed4d) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed4d*0.95);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed3d);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed3d);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed4d);
}

void MRB2(int speed5d, int speed6d) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed5d*0.95);
  ledcWrite(RPWM_Output2, speed6d);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed6d);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed5d);
}

void MLB2(int speed7d, int speed8d) {
  ledcWrite(RPWM_Output1, speed8d*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed7d);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed7d);
  ledcWrite(RPWM_Output4, speed8d);
  ledcWrite(LPWM_Output4, 0);
}

void TR(int speed9) {
  ledcWrite(RPWM_Output1, speed9*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, speed9);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed9);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed9);
}

void TL(int speed10) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed10*0.95);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed10);
  ledcWrite(RPWM_Output3, speed10);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, speed10);
  ledcWrite(LPWM_Output4, 0);
}

void TRs(int speed9b) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, speed9b);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed9b);
}

void TLs(int speed10b) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed10b);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, speed10b);
  ledcWrite(LPWM_Output4, 0);
}

void MR1(int speed11) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed11*0.95);
  ledcWrite(RPWM_Output2, speed11);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed11);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed11);
}

void ML(int speed12) {
  ledcWrite(RPWM_Output1, speed12*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed12);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed12);
  ledcWrite(RPWM_Output4, speed12);
  ledcWrite(LPWM_Output4, 0);
}

void FW(int speed13) {
  ledcWrite(RPWM_Output1, speed13*0.95);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, speed13);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, speed13);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, speed13);
  ledcWrite(LPWM_Output4, 0);
}

void BW(int speed14) {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, speed14*0.95);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, speed14);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, speed14);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, speed14);
}

void ST() {
  ledcWrite(RPWM_Output1, 0);
  ledcWrite(LPWM_Output1, 0);
  ledcWrite(RPWM_Output2, 0);
  ledcWrite(LPWM_Output2, 0);
  ledcWrite(RPWM_Output3, 0);
  ledcWrite(LPWM_Output3, 0);
  ledcWrite(RPWM_Output4, 0);
  ledcWrite(LPWM_Output4, 0);
}

void setup() {
  Serial.begin(115200);
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);
  pinMode(RY5, OUTPUT);
  ledcSetup(RPWM_Output1, 10000, 8);
  ledcSetup(LPWM_Output1, 10000, 8);
  ledcSetup(RPWM_Output2, 10000, 8);
  ledcSetup(LPWM_Output2, 10000, 8);
  ledcSetup(RPWM_Output3, 10000, 8);
  ledcSetup(LPWM_Output3, 10000, 8);
  ledcSetup(RPWM_Output4, 10000, 8);
  ledcSetup(LPWM_Output4, 10000, 8);
  ledcAttachPin(PWM1, RPWM_Output1);
  ledcAttachPin(PWM2, LPWM_Output1);
  ledcAttachPin(PWM3, RPWM_Output2);
  ledcAttachPin(PWM4, LPWM_Output2);
  ledcAttachPin(PWM5, RPWM_Output3);
  ledcAttachPin(PWM6, LPWM_Output3);
  ledcAttachPin(PWM7, RPWM_Output4);
  ledcAttachPin(PWM8, LPWM_Output4);



  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("40:91:51:fd:6d:26");
  Serial.println("Ready.");
}

void loop() {
  if (PS4.Cross() == 1 && PS4.R1() != 1 && PS4.R2() != 1) {
    Cross_pressed();
  }
  else if (PS4.Circle() == 1 && PS4.R1() != 1 && PS4.R2() != 1) {
    Circle_pressed();
  }
  else if (PS4.Square() == 1 && PS4.R1() != 1 && PS4.R2() != 1) {
    Square_pressed();
  }
  else if (PS4.Triangle() == 1 && PS4.R1() != 1 && PS4.R2() != 1) {
    Triangle_pressed();
  }
  else if (PS4.Cross() == 1 && PS4.R1() == 1 && PS4.R2() != 1) {
    R1Cross_pressed();
  }
  else if (PS4.Circle() == 1 && PS4.R1() == 1 && PS4.R2() != 1) {
    R1Circle_pressed();
  }
  else if (PS4.Square() == 1 && PS4.R1() == 1 && PS4.R2() != 1) {
    R1Square_pressed();
  }
  else if (PS4.Triangle() == 1 && PS4.R1() == 1 && PS4.R2() != 1) {
    R1Triangle_pressed();
  }
  else if (PS4.Cross() == 1 && PS4.R2() == 1 && PS4.R1() != 1) {
    R2Cross_pressed();
  }
  else if (PS4.Circle() == 1 && PS4.R2() == 1 && PS4.R1() != 1) {
    R2Circle_pressed();
  }
  else if (PS4.Square() == 1 && PS4.R2() == 1 && PS4.R1() != 1) {
    R2Square_pressed();
  }
  else if (PS4.Triangle() == 1 && PS4.R2() == 1 && PS4.R1() != 1) {
    R2Triangle_pressed();
  }
  else if (PS4.Share() == 1) {
    Share_pressed();
  }
  else if (PS4.Down() == 1 && PS4.L2() != 1) {
    Down_pressed();
  }
  else if (PS4.Left() == 1 && PS4.L2() != 1) {
    Left_pressed();
  }
  else if (PS4.Right() == 1 && PS4.L2() != 1) {
    Right_pressed();
  }
  else if (PS4.Up() == 1 && PS4.L2() == 1 ) {
    R2Up_pressed();
  }
  else if (PS4.Down() == 1 && PS4.L2()) {
    R2Down_pressed();
  }
  else if (PS4.Left() == 1 && PS4.L2() == 1) {
    R2Left_pressed();
  }
  else if (PS4.Right() == 1 && PS4.L2() == 1) {
    R2Right_pressed();
  }
  else {
    Release();
  }

  int ys = 200; //ความเร็วปกติ
  int z = ys;
  int g = 255; //ความเร็วปกติสูง
  int gb = g - ys;
  int gb2 = gb + ys;
  if (PS4.R2() == 1) {
    z = z + gb;
  }

  int cha1up = map((PS4.LStickX()), 0, 128, 0, z);
  int cha1down = map((PS4.LStickX()), 0, -128, 0, z);
  int cha2up = map((PS4.LStickY()), 0, 128, 0, z);
  int cha2down = map((PS4.LStickY()), 0, -128, 0, z);
  int cha3up = map((PS4.RStickX()), 0, 128, 0, z);
  int cha3down = map((PS4.RStickX()), 0, -128, 0, z);
  int Sixma1 = cha2up - cha1up;
  int Sixma1d = cha1up - cha2up;
  int Sixma2 = cha2up - cha1down;
  int Sixma2d = cha1down - cha2up;

  int Sixma3 = cha2down - cha1up;
  int Sixma3d = cha1up - cha2down;

  int Sixma4 = cha2down - cha1down;
  int Sixma4d = cha1down - cha2down;

  int MAX = 20;

  if (cha1up < MAX && cha1down < MAX && cha2up < MAX && cha2down < MAX && cha3up < MAX && cha3down < MAX) {
    ST();
  } else if (Sixma1 > MAX && cha2up > MAX && cha1up > MAX) {
    MRT1(cha2up, Sixma1);
  } else if (Sixma2 > MAX && cha2up > MAX && cha1down > MAX) {
    MLT1(cha2up, Sixma2);
  } else if (Sixma1d > MAX && cha2up > MAX && cha1up > MAX) {
    MRT2(cha1up, Sixma1d);
  } else if (Sixma2d > MAX && cha2up > MAX && cha1down > MAX) {
    MLT2(cha1down, Sixma2d);
  } else if (Sixma3 > MAX && cha2down > MAX && cha1up > MAX) {
    MRB1(cha2down, Sixma3);
  } else if (Sixma4 > MAX && cha2down > MAX && cha1down > MAX) {
    MLB1(cha2down, Sixma4);
  } else if (Sixma3d > MAX && cha2down > MAX && cha1up > MAX) {
    MRB2(cha1up, Sixma3d);
  } else if (Sixma4d > MAX && cha2down > MAX && cha1down > MAX) {;
    MLB2(cha1down, Sixma4d);
  } else if (cha1up > MAX && cha2up < MAX && cha2down < MAX) {
    MR1(cha1up);
  } else if (cha1down > MAX && cha2up < MAX && cha2down < MAX) {
    ML(cha1down);
  } else if (cha2up > MAX && cha1up < MAX && cha1down < MAX) {
    FW(cha2up);
  } else if (cha2down > MAX && cha1up < MAX && cha1down < MAX) {
    BW(cha2down);
  } else if (cha3up > MAX && z == ys) {
    TRs(cha3up);
  } else if (cha3down > MAX && z == ys) {
    TLs(cha3down);
  } else if (cha3up > MAX && z == gb2) {
    TR(cha3up);
  } else if (cha3down > MAX && z == gb2) {
    TL(cha3down);
  }

}
