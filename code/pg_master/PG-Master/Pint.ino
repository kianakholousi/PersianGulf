#include <Pixy.h>
//#include <PixyI2C.h>
//#include <PixySPI_SS.h>
//#include <PixyUART.h>
//#include <TPixy.h>

#include <Wire.h>
#include <SPI.h>
//#include <Pixy.h>
//#include <math.h>
//#include <EEPROM.h>
//#include "Adafruit_VL53L0X.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>
//#include <utility/imumaths.h>
//Pixy pcam;
//IntervalTimer myTimer;
//#define Buzzer 21
//#define Shoot 10
//#define PWMlf 38
//#define digitalPINlf 39
//#define PWMlb  14
//#define digitalPINlb  37
//#define PWMrf  2
//#define digitalPINrf 8
//#define PWMrb  7
//#define digitalPINrb  6
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//adafruit_bno055_offsets_t calibrationData;
//sensors_event_t event;
//adafruit_bno055_offsets_t newCalib;
//float Ba, GYa, GBa, reduction = 0, mamadagha;
//int ba, BC, Bx, By, BxCenter, ByCenter, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy, /* GAy*/;
//int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//int Compass = 0, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
//int Other_distance , Other_Ba, l1, l2, r1, r2, i = 0, setbno, distance, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, BCount = 0, flag;
//char buff[9];
//bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag;
void set_pins(){
  //------------MOTORS-------------------
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(7,  OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(2,  OUTPUT);
  pinMode(8,  OUTPUT);
  analogWriteFrequency(38, 29296.875);
  //------------out sensors---------------
  pinMode(Bit, INPUT);//49
  pinMode(32, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  //------------shoot---------------------
  pinMode(Shoot, OUTPUT);
  //------------battery feedback----------
  pinMode(20, INPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  //------------DIP switch-----------------
  pinMode(36, INPUT);
  pinMode(35, INPUT);
  pinMode(15, INPUT);
  //------------Buzzer--------------------
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  delay(50);
  digitalWrite(21, LOW);
  delay(30);
  digitalWrite(21, HIGH);
  delay(50);
  digitalWrite(21, LOW);
  pinMode(29, INPUT);
}
//#include <Wire.h>
#include <SPI.h>
#include <Pixy.h>
#include <math.h>
//#include <EEPROM.h>
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
float Ba, GYa, GBa, reduction = 0;
int BCounter, Bx, By, BxCenter, ByCenter, DistanceB, GYx, GYy, GYxCenter, GYyCenter, DistanceGY, GBx, GBy, GBxCenter, GByCenter, DistanceGB, Gy, GAy;
int OS[10]= {0,0,0,0,0,0,0,0,0,0} , OSP[10]= {0,0,0,0,0,0,0,0,0,0}, set_m = 0, Compass = 0, Cmp = 0, setcmp = 0, set_s, refresher = 0, Ball = 0;
int Other_distance , Other_Ba, l1, l2, r1, r2, i = 0, setbno, distance, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, ShootCounter = 0, BCount = 0, DShift;
char buff[9];
boolean Fr1 = 0, Fr2 = 0, Ri1 = 0, Ri2 = 0, Ba1 = 0, Ba2 = 0, Le1 = 0, Le2 = 0, goalieTeach;
int  BAxcenter, BayCenter, ba, k;
