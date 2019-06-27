//#include "Pint.ino"
#include <Pixy.h>
#include <Wire.h>
#include <SPI.h>
#include <math.h>
#include <EEPROM.h>
#include "Adafruit_VL53L0X.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>
//#include <utility/imumaths.h>
Pixy pcam;
IntervalTimer myTimer;
#define Buzzer 11
#define Shoot 30
#define PWMlf 21
#define digitalPINlf 20
#define PWMlb  23
#define digitalPINlb  22
#define PWMrf  10
#define digitalPINrf 9
#define PWMrb  6
#define digitalPINrb 5
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//adafruit_bno055_offsets_t calibrationData;
//sensors_event_t event;
//adafruit_bno055_offsets_t newCalib;
float GYa, GBa, reduction = 0, mamadagha;
int FO, FI, RO, RI, BO, BI, LO, LI, NFO, NFI, NRO, NRI, NBO, NBI, NLO, NLI;
int Ba, DShift, BA, BC, Bx, By, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Compass = 0, Compass2, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
int  i = 0, setbno, dis_back, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, yell;
bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag = true, south = false;
int  BAxcenter, BayCenter, k, shif;
void setup() {
  //------------VL53L0X_d----------------
  //  lox.begin();
  SPI.setMOSI(28);
  SPI.setSCK(27);
  Wire.setSCL(7);
  Wire.setSDA(8);
  //------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  //  Serial5.begin(9600);
  pcam.init();
  Wire.begin();
  set_pins();
  eeprom_read();
}

//------------INTER_UP_T---------------------
void Counter()
{
  reduction = 0.9;
  flag = true;
  BC++;
  set_s = -spin_speed(1, 100, 100);
  if (BC > 3) Ball = false;
  else Ball = true;
}

void loop() {

  SET();
  OC();
  col_ang();
  if (Ball)  fallout();
  else   STOP();
}
