#include <Wire.h>
#include <SPI.h>
#include <Pixy.h>
#include <math.h>
#include <EEPROM.h>
#include "Adafruit_VL53L0X.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
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
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
Adafruit_BNO055 bno = Adafruit_BNO055(55);
adafruit_bno055_offsets_t calibrationData;
sensors_event_t event;
adafruit_bno055_offsets_t newCalib;
float Ba, GYa, GBa, reduction = 0;
int BCounter, Bx, By, BxCenter, ByCenter, DistanceB, GYx, GYy, GYxCenter, GYyCenter, DistanceGY, GBx, GBy, GBxCenter, GByCenter, DistanceGB, Gy, GAy;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, set_m = 0, Compass = 0, Cmp = 0, setcmp = 0, set_s, refresher = 0, Ball = 0;
int Other_distance , Other_Ba, l1, l2, r1, r2, i = 0, setbno, distance, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, ShootCounter = 0, BCount = 0, DShift;
char buff[9];
boolean Fr1 = 0, Fr2 = 0, Ri1 = 0, Ri2 = 0, Ba1 = 0, Ba2 = 0, Le1 = 0, Le2 = 0, goalieTeach;
int  BAxcenter, BayCenter, ba, k;
//void dipSwitch()
//{
//  if (digitalRead(36) == HIGH)
//  {
////    digitalWrite(Buzzer, HIGH);
////    delay(10);
//    goalieTeach = 3;
//  }
//  else if (digitalRead(36) == LOW)
//  {
////    digitalWrite(Buzzer, LOW);
//    goalieTeach = 2;
//  }
//}

void setup()
{
  //------------VL53L0X_d----------------
  lox.begin();
  //------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  //  Serial5.begin(9600);
  analogWriteResolution(10);
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
//------------Timer---------------------
void Counter()
{
  //  //  SRF_Reader();
  //  ShootCounter++;
  //  if (ShootCounter > 7) Shootflag = 1;
  //  else Shootflag = 0;
  BCounter++;
  if (BCounter > 2) Ball = 0;
  else Ball = 1;
  ////  r1 = 0; //0
  ////  l1 = 180; //210
  ////  r2 = 180; //150
  ////  l2 = 360; //330
  //   //  set_s = -spin_yellow(20);
  //   set_s = -spin_speed(1, 50, 20);
}

int Bit = 49; //49
/*
  void loop()
  {

  //    set_s = -spin_yellow(20);
  reduction = 0.9;
  //Calibration();
  //  Read_bno();
  //  Battery();
  OS_Comparison();
  OS_Reader();
  Read_Cmp();
  col_ang();
    VL_Reader();
  //    dipSwitch();
  //  SRF_Reader();
  //------------eeprom-----------------
  if (digitalRead(29) == LOW)
  {
    while (digitalRead(29) == LOW)
    {
      digitalWrite(21, HIGH);
      //------------set out sensors on green
      OSP[1] = analogRead(Bit); //F1
      OSP[2] = analogRead(32); //F2
      OSP[3] = analogRead(23); //R1
      OSP[4] = analogRead(22); //R2
      OSP[5] = analogRead(18); //L1
      OSP[6] = analogRead(19); //L2
      OSP[7] = analogRead(16); //B1
      OSP[8] = analogRead(17); //B2
      Read_Cmp();
      setcmp = Compass;
      //      Read_bno();
      //      setcmp = bnox;
    }
    eeprom_write();
    digitalWrite(21, LOW);
  }
  //  if (Ba<30 || Ba>330)
  //  {
  //    shift();
  //    Do_Shoot();
  //  }
  //  else {
  //    MOTOR(255,255,255,255);
  //  }

  // shift();
  // Do_Shoot();
  //------------sending data-------------
  //  sprintf(d, "(%03d%03d", (int) Ba, DistanceB );
  //  Serial5.println(d);
  //------------monitor------------------
  //    Serial.print(set_s); Serial.print(" * "); Serial.println(GYa);
  //    delay(1);
  //    Serial.println(distance);
  //  delay(1);

  //------------circle test--------------
  //  for (int i=0; i<=360 ; i++)
  //  {
  //    mot_ang(i);
  //    delay(1);
  //  }
  //------------Show out sensors----------
  //         sprintf(buff,"F1 %d F2 %d R1 %d R2 %d B1 %d B2 %d L1 %d L2 %d" ,///*Fr1,Fr2,Ri1,Ri2,Ba1,Ba2,Le1,Le2// OS[1],OS[2],OS[3],OS[4],OS[7],OS[8],OS[5],OS[6]);
  //         Serial.println(buff);
  //         delay(50);
    //------------GOALIE BLUE---------------------
  //        if (Ball == 1)
  //        {
  //          if ((DistanceB < 40 || (Ba > 90 && Ba < 270)) && distance<70)
  //            fol_out();
  //          else MoveWidth_d();
  //        }
  //        else
  //          Backtogoal_d();
  //------------FORWARD-------------------
            fol_out();

  //------------GOALIE YELLOW---------------------
  //
  //         if (Ball == 1 && distance<70)
  //          {
  //            if ((DistanceB < 50 || (Ba > 90 && Ba < 270)) )
  //              fol_out();
  //            else MoveWidth();
  //          }
  //          else
  //            Backtogoal();
  } */


//int s = 0;
void loop()
{
  reduction = 0.6;

  //  if (digitalRead(29) == LOW)
  //  {
  //    while (digitalRead(29) == LOW)
  //    {
  //      digitalWrite(21, HIGH);
  //      Read_Cmp();
  //      setcmp = Compass;
  //    }
  //    digitalWrite(21, LOW);
  //  }
  //  Read_Cmp();
  //  set_s = spin_speed(1, 50, 20);
  //  set_s = spin_speed(1, 15, 3);
  //  Serial.println(DistanceB);
  //  Serial.println(DShift);
  set_s = 0;
  //  set_s = GYa * 15;
  col_ang();
  //  mot_ang(GYa);
  /*      MAIN        */
  if (Ball) shift();
  else  STOP();
  /*                  */
  //  STOP();
}
