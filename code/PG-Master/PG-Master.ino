//#include "Pint.ino"
#include <Pixy.h>
#include <Wire.h>
#include <SPI.h>
#include <math.h>
#include <EEPROM.h>
//#include "Adafruit_VL53L0X.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>
//#include <utility/imumaths.h>
Pixy pcam;
IntervalTimer myTimer;

#define Buzzer 21
#define Shoot 10
#define PWMlf 38
#define digitalPINlf 39
#define PWMlb  14
#define digitalPINlb  37
#define PWMrf  2
#define digitalPINrf 8
#define PWMrb  7
#define digitalPINrb  6
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//adafruit_bno055_offsets_t calibrationData;
//sensors_event_t event;
//adafruit_bno055_offsets_t newCalib;
float Ba, GYa, GBa, reduction = 0, mamadagha;
int DShift, BA, BC, Bx, By, BxCenter, ByCenter, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Compass = 0, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
int Other_distance , Other_Ba, l1, l2, r1, r2, i = 0, setbno, distance, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, BCount = 0,yell;
char buff[9];
bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag = false;
int  BAxcenter, BayCenter, k;
int Bit = 49;
void setup() {
  //------------VL53L0X_d----------------
  //  lox.begin();
  //------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  Serial5.begin(9600);
  pcam.init();
  Wire2.begin();
  set_pins();
  eeprom_read();
  //------------bBNO055-----------------
  //  bno.begin();
  //  EEPROM.get(eeAddress, calibrationData);
  //  bno.setSensorOffsets(calibrationData);
  //  bno.setExtCrystalUse(true);
  //    bno.getSensorOffsets(newCalib);
}

void loop() {
  reduction = 0.6;
  mot_ang(0);
}
