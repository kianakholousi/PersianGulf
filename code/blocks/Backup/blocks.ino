#include <Wire.h>
#include <SPI.h>
#include <Pixy.h>
#include <math.h>
#include <EEPROM.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
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
float Ba, GYa, GBa, reduction = 0;
int BCounter, Bx, By, BxCenter, ByCenter, DistanceB, GYx, GYy, GYxCenter, GYyCenter, DistanceGY, GBx, GBy, GBxCenter, GByCenter, DistanceGB, Gy, GAy, ShootCounter = 0;
int OS[9] = {0, 0, 0, 0, 0, 0, 0, 0}, OSP[9] = {0, 0, 0, 0, 0, 0, 0, 0}, Compass = 0, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0, Ball = 0, BCount = 0;
int  i = 0,setbno,distance, Shootflag = 0;
char buff[9];
String BNOS;
boolean Fr1 = 0, Fr2 = 0, Ri1 = 0, Ri2 = 0, Ba1 = 0, Ba2 = 0, Le1 = 0, Le2 = 0;
int Other_distance , Other_Ba, l, l2, r, r2, bno;
//------------reading compass---------
void Read_Cmp()
{
  Wire2.beginTransmission(96);  ////starts communication with cmp03
  Wire2.write(2);                    /////sends the register we wish to read
  Wire2.endTransmission();
  Wire2.requestFrom(96, 2);     /////requests high byte
  Compass = Wire2.read() << 8 | Wire2.read();
  Wire2.endTransmission();

  Compass = map(Compass, 0, 3600, 0, 1023);
  if (Compass - setcmp < 0) Cmp = 1023 - (setcmp - Compass);
  else  Cmp = Compass - setcmp;
  if (Cmp > 512) Cmp = Cmp - 1023;
}
//------------reading BNO055----------
void Read_bno()
{
  bno = map(bno, 0, 360, 0, 1023);
  if (bno - setcmp < 0) Cmp = 1023 - (setcmp - bno);
  else  Cmp = bno - setcmp;
  if (Cmp > 512) Cmp = Cmp - 1023;
}
//------------calibration------------

void Calibration()
{
  byte highByte;
  byte lowByte;

  Serial.println("north");
  delay(5000);

  Wire2.beginTransmission(96);//starts communication with cmps03
  Wire2.write(15); //Sends the register we wish to read
  Wire2.write(byte(0xFF));
  Wire2.endTransmission();

  Serial.println("east");
  delay(5000);

  Wire2.beginTransmission(96);
  Wire2.write(15);
  Wire2.write(byte(0xFF)); //Sends the register we wish to read
  Wire2.endTransmission();

  Serial.println("south");
  delay(5000);

  Wire2.beginTransmission(96);
  Wire2.write(15);
  Wire2.write(byte(0xFF)); //Sends the register we wish to read
  Wire2.endTransmission();

  Serial.println("west");
  delay(5000);

  Wire2.beginTransmission(96);
  Wire2.write(15);
  Wire2.write(byte(0xFF)); //Sends the register we wish to read
  Wire2.endTransmission();


  while (1) {
    Wire2.beginTransmission(96);
    Wire2.write(1);
    Wire2.endTransmission();

    Wire2.requestFrom(96, 2);        //requests high byte
    highByte = Wire.read();           //reads the byte as an integer
    int bearing = highByte;
    Serial.println(bearing);
    delay(100);
  }
}

//------------spin speed------------
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  compass_input = Cmp ;
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + added_value;
  else if (compass_input <= (-zero_degree) )
    compass_output = -((-compass_input) / divided_value) - added_value;
  else
    compass_output = 0;
  return compass_output;
}

//------------spin yellow------------
signed int spin_yellow( int added_value)
{
  int input = 0, output = 0;
  input = GYa ;
  if ( input > 180 && input < 350 )
    output = (input) + added_value;
  else if (input <= 180 && input > 10 )
    output = -((input) ) - added_value - 180;
  else
    output = 0;
  return output;
}
//------------Timer---------------------
void Counter()
{
  ShootCounter++;
  if (ShootCounter > 7) Shootflag = 1;
  else Shootflag = 0;
  BCounter++;
  if (BCounter > 2) Ball = 0;
  else Ball = 1;
//  nano();
//   set_s= -spin_yellow(18);
set_s = -spin_speed(1,50, 20);
}
void setup()
{
//------------VL53L0X_d----------------
  lox.begin();
//------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  Serial5.begin(9600);
  analogWriteResolution(10);
  pcam.init();
  Wire2.begin();
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
  pinMode(31, INPUT);//49
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
//------------DIP switch-----------------
  pinMode(36, INPUT);
  pinMode(35, INPUT);
  pinMode(15, INPUT);
  // reading out sensors from eeprom (Resolution(8) to (10))
  setcmp = (EEPROM.read(0)  << 8) | EEPROM.read(1);
  OSP[1] = (EEPROM.read(2)  << 8) | EEPROM.read(3);
  OSP[2] = (EEPROM.read(4)  << 8) | EEPROM.read(5);
  OSP[3] = (EEPROM.read(6)  << 8) | EEPROM.read(7);
  OSP[4] = (EEPROM.read(8)  << 8) | EEPROM.read(9);
  OSP[5] = (EEPROM.read(10) << 8) | EEPROM.read(11);
  OSP[6] = (EEPROM.read(12) << 8) | EEPROM.read(13);
  OSP[7] = (EEPROM.read(14) << 8) | EEPROM.read(15);
  OSP[8] = (EEPROM.read(16) << 8) | EEPROM.read(17);
}

void loop()
{
  VL53L0X_RangingMeasurementData_t measure;
  reduction = 1;
  //Calibration();
  OS_Comparison();
  OS_Reader();
  Read_Cmp();
  col_ang();
  
   
//------------eeprom-----------------
  if (digitalRead(29) == LOW)
  {
    while (digitalRead(29) == LOW)
    {
      digitalWrite(21, HIGH);
//------------set out sensors on green
      OSP[1] = analogRead(31); //F1
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
        //      setcmp = bno;
    }
    EEPROM.write(0, highByte(setcmp));  EEPROM.write(1, lowByte(setcmp));
    EEPROM.write(2, highByte(OSP[1]));  EEPROM.write(3, lowByte(OSP[1]));
    EEPROM.write(4, highByte(OSP[2]));  EEPROM.write(5, lowByte(OSP[2]));
    EEPROM.write(6, highByte(OSP[3]));  EEPROM.write(7, lowByte(OSP[3]));
    EEPROM.write(8, highByte(OSP[4]));  EEPROM.write(9, lowByte(OSP[4]));
    EEPROM.write(10, highByte(OSP[5])); EEPROM.write(11, lowByte(OSP[5]));
    EEPROM.write(12, highByte(OSP[6])); EEPROM.write(13, lowByte(OSP[6]));
    EEPROM.write(14, highByte(OSP[7])); EEPROM.write(15, lowByte(OSP[7]));
    EEPROM.write(16, highByte(OSP[8])); EEPROM.write(17, lowByte(OSP[8]));
    digitalWrite(21, LOW);
  }
//------------sending data-------------
//  sprintf(d, "(%03d%03d", (int) Ba, DistanceB );
//  Serial5.println(d);
//------------VL53L0X_d----------------
   lox.rangingTest(&measure, false);
   if (measure.RangeStatus != 4) 
   {  
       distance=measure.RangeMilliMeter/10;
//     Serial.println(distance);
   } 
   else distance=150;
//------------monitor------------------
//    Serial.print(GYa); Serial.print(" * "); Serial.println(DistanceGY);
//    delay(50);
//   Serial.println(Ba);
//   delay(50);
//------------circle test--------------
  //for (int i=0; i<=360 ; i++)
  //{
  //  mot_ang(i);
  //   delay(1);
  //}
//  mot_ang(0);
//MOTOR(512,512,-512,-512);
//------------Show out sensors----------
    //     Show out sensors
//      sprintf(buff,"F1 %d F2 %d R1 %d R2 %d B1 %d B2 %d L1 %d L2 %d" ,/* Fr1,Fr2,Ri1,Ri2,Ba1,Ba2,Le1,Le2 */OS[1],OS[2],OS[3],OS[4],OS[7],OS[8],OS[5],OS[6]);
//      Serial.println(buff);
//      delay(50);
//------------FORWARD-------------------
      if (Ball==1)
      {
////        shift();
       fol_out();
      }
      else
       STOP();
      Do_Shoot();

//------------GOALIE---------------------
//    if (Ball == 1)
//    {
//      if (DistanceB < 40 || (Ba > 90 && Ba < 270))
//  
//        fol_out();
//      //     follow();
//  
//      else MoveWidth_d();
//    }
//    else
//      Backtogoal_d();
//      Do_Shoot();

        
}
