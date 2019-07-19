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
IntervalTimer Receiver;
#define address 0x60
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
int Ba, DShift, BA, BC, Bx, By, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy, Gy360;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Compass = 0, Compass2, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
int  i = 0, setbno, dis_back, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, yell;
bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag = true, DisB, Disbl, stringComplete = false ;
String  Ang = "", dis = "";
int  BAxcenter, BayCenter, k, shif, Angle, Distancebl;
char joda = 55, sit;
void setup() {
  //------------VL53L0X_d----------------
  lox.begin();
  SPI.setMOSI(28);
  SPI.setSCK(27);
  Wire.setSCL(7);
  Wire.setSDA(8);
  Wire2.setSCL(3);
  Wire2.setSDA(4);
  //------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Receiver.begin(BTReceiver, 100000);
  Serial.begin(9600);
  Serial5.begin(9600);
  pcam.init();
  Wire.begin();
  set_pins();
  eeprom_read();
  //    Calibration();
}

//------------INTER_UP_T---------------------
void Counter()
{

  //  reduction = 0.9;
  flag = 0;
  //  if (flag==1) set_s = -spin_speed(1, 100, 100); // yellow
  // else if(flag==0) set_s = -spin_speed(1, 30, 20); // cmps03
  set_s = -spin_speed(1, 30, 30); // cmps03
  //  set_s = -spin_speed(1, 15, 100); // yellow

  BC++;

  if (BC > 3) Ball = false;
  else Ball = true;
  SHC++;
}

void loop() {


  col_ang();
  VL_Reader();
  OC();
  SET();
  //    STOP();

  //----------goalkeeper
  reduction = 0.7;
//  if (!(Ball) || DistanceB > 90 || dis_back > 500 )
//  {
//    Backtogoal();
//  }
//  else if (dis_back < 300)
//  {
//    mot_ang(0);
//  }
//  else if ((Ba < 270 && Ba > 90) || (DistanceB < 85 && dis_back < 650)) fallout();
//   if (Ball && DistanceB < 120 )
//      {
//        MoveWidth_vl();
//      }
//////////////////////////////
    if (dis_back < 300)
    {
      mot_ang(0);
    }
    if ((Ba < 270 && Ba > 90) || (DistanceB < 85 && dis_back < 700)) fallout();
    else if (dis_back > 500)
    {
      mot_ang(Gy360);
    }
    else
    {
      if (Ball && DistanceB < 120 )
      {
        MoveWidth_vl();
        //      fallout();
      }
      else STOP();
    }
  //------------forward
//  if (Ball) fallout();
//  else STOP();
}
