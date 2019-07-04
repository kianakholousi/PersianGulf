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
IntervalTimer Sender;
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
#define digitalPINrb  5
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//adafruit_bno055_offsets_t calibrationData;
//sensors_event_t event;
//adafruit_bno055_offsets_t newCalib;
float GYa, GBa, reduction = 0, mamadagha;
int FO, FI, RO, RI, BO, BI, LO, LI, NFO, NFI, NRO, NRI, NBO, NBI, NLO, NLI;
int Ba, DShift, BA, BC, Bx, By, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy , arz , tool , GYa_360;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Compass = 0, Compass2, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
int  i = 0, setbno, dis_back, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, yell;
bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag = false, RSit;
int  BAxcenter, BayCenter, k, shif;
void setup() {
  SPI.setMOSI(28);
  SPI.setSCK(27);
  Wire2.setSCL(3);
  Wire2.setSDA(4);
  Wire.setSCL(7);
  Wire.setSDA(8);
  //------------VL53L0X_d----------------
  lox.begin();
  //----------------------------------
  myTimer.begin(Counter, 100000);
  Sender.begin(BTSender, 100000);
  Serial.begin(9600);
  pcam.init();
  set_pins();
  //  Serial5.begin(9600);
  Wire.begin();
  Wire2.begin();
  eeprom_read();
  //    Calibration();
}

//------------INTER_UP_T---------------------
void Counter()
{
  //if(abs(Cmp)<200) flag=true;
  //else flag= false;
  flag = 0;
  reduction = 0.9;
  Read_Cmp();
//  set_s =  -spin_speed(1, 10, 100); //yellow
     set_s =  -spin_speed(1, 30, 20);//cmps03
  flag = 1;
  reduction = 0.9;
  Read_Cmp();
  set_s =  -spin_speed(1, 10, 100); //yellow
//     set_s =  -spin_speed(1, 30, 20);//cmps03

  BC++;
  if (BC > 5) Ball = false;
  else Ball = true;
  SHC++;
}

void loop()
{
  SET();
  OC();
  col_ang();
  //  if (Ball) {
  //    if (flag == 1)  fallout();
  //    else  fout();
  //  }
  //  else  STOP();
Serial.print(Ba);
Serial.print("|||");
Serial.print(GYa);
Serial.print("|||");
Serial.println(yell);
  if (Ball) fallout();
  else STOP();
}
