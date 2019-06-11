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
  while (1)
  {
    Wire2.beginTransmission(96);
    Wire2.write(1);
    Wire2.endTransmission();
    Wire2.requestFrom(96, 2);        //requests high byte
    highByte = Wire2.read();           //reads the byte as an integer
    int bearing = highByte;
    Serial.println(bearing);
    delay(100);
  }
}

//////////////////////////////////
void Read_Cmp()
{
  Wire2.beginTransmission(96);  ////starts communication with cmp03
  Wire2.write(2);                    /////sends the register we wish to read
  Wire2.endTransmission();
  Wire2.requestFrom(96, 2);     /////requests high byte
  Compass2 = Wire2.read() << 8 | Wire2.read();
  Wire2.endTransmission();
  Compass = map(Compass2, 0, 3600, 0, 1023);
  //  if (Compass - setcmp < 0) Cmp = 1023 - (setcmp - Compass);
  //  else  Cmp = Compass - setcmp;
  //  if (Cmp > 512) Cmp = Cmp - 1023;
  //////baze bandii
  int b, a;
  a =  Compass - setcmp;
  if (a > 0) b = a;
  else b = a + 1023;
  if (b > 512) b = b - 1023;
  else b = b;
  Cmp = -b;
}
 //------------reading BNO055----------
//void Read_bno()
//{
//  uint8_t system, gyro, accel, mag;
//  system = gyro = accel = mag = 0;
//  bno.getEvent(&event);
//  bno.getCalibration(&system, &gyro, &accel, &mag);
//  //----------BNO---calibration
//  //  Serial.print("Sys:");
//  //  Serial.print(system, DEC);
//  //  Serial.print(" G:");
//  //  Serial.print(gyro, DEC);
//  //  Serial.print(" A:");
//  //  Serial.print(accel, DEC);
//  //  Serial.print(" M:");
//  //  Serial.print(mag, DEC);
//  //  Serial.print("\t");
//  if (bno.isFullyCalibrated() && Calibrate_BNO == 0)
//  {
//    bno.getSensorOffsets(newCalib);
//    EEPROM.put(eeAddress, newCalib);
//    Serial.println("Calibrated");
//    Calibrate_BNO = 1;
//    delay(1000);
//  }
//  else
//  {
//    bnox = event.orientation.x;
//  }
//  bnox = map(bnox, 0, 360, 0, 1023);
//  if (bnox - setcmp < 0) Cmp = 1023 - (setcmp - bnox);
//  else  Cmp = bnox - setcmp;
//  if (Cmp > 512) Cmp = Cmp - 1023;
//}
void SRF_Reader()
{
  Wire2.beginTransmission(113); // transmit to device #112 (0x70)
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c adressing uses the high 7 bits so it's 112
  Wire2.write(byte(0x00));      // sets register pointer to the command register (0x00)
  Wire2.write(byte(0x51));      // command sensor to measure in "CENTIMETERS" (0x51)
  // use 0x50 for inches
  // use 0x52 for ping microseconds
  Wire2.endTransmission();      // stop transmitting

  // step 2: wait for readings to happen
  delay(70);                   // datasheet suggests at least 65 milliseconds

  // step 3: instruct sensor to return a particular echo reading
  Wire2.beginTransmission(113); // transmit to device #112
  Wire2.write(byte(0x02));      // sets register pointer to echo #1 register (0x02)
  Wire2.endTransmission();      // stop transmitting

  // step 4: request reading from sensor
  Wire2.requestFrom(113, 2);    // request 2 bytes from slave device #113

  // step 5: receive reading from sensor
  if (Wire2.available() >= 2) { // if two bytes were received
    dis_back = Wire2.read();     // receive high byte (overwrites previous reading)
    dis_back = dis_back << 8;    // shift high byte to be high 8 bits
    dis_back = Wire2.read();    // receive low byte as lower 8 bits
    //    Serial.print(dis_back);
  }

}
//------------VL53L0X_d----------------
//void VL_Reader()
//{
//  VL53L0X_RangingMeasurementData_t measure;
//  lox.rangingTest(&measure, false);
//  if (measure.RangeStatus != 4)
//  {
//    dis_back = measure.RangeMilliMeter / 10;
//    //         Serial.println(dis_back);
//    //         delay(50);
//  }
//  else dis_back = 150;
//}

////////////////////outsensors///////////////////
void OC()
{
  OS_Reader();
  if (OS[1] - OSP[1] > 60) fa = 1;
  else fa = 0;
  if (OS[2] - OSP[2] > 60) fb = 1;
  else fb = 0;
  if (OS[3] - OSP[3] > 60) ra = 1;
  else ra = 0;
  if (OS[4] - OSP[4] > 60) rb = 1;
  else rb = 0;
  if (OS[5] - OSP[5] > 60) la = 1;
  else la = 0;
  if (OS[6] - OSP[6] > 60) lb = 1;
  else lb = 0;
  if (OS[7] - OSP[7] > 50) ba = 1;
  else ba = 0;
  if (OS[8] - OSP[8] > 170)  bb = 1;
  else bb = 0;
}
//------reading out sensors----
void OS_Reader()
{
  OS[1] = analogRead(49); //49
  OS[2] = analogRead(32);
  OS[3] = analogRead(23);
  OS[4] = analogRead(22);
  OS[5] = analogRead(18);
  OS[6] = analogRead(19);
  OS[7] = analogRead(16);
  OS[8] = analogRead(17);
}
///////////////////////////////////////////////////
//------------VL53L0X_d----------------
//void VL_Reader()
//{
//  VL53L0X_RangingMeasurementData_t measure;
//  lox.rangingTest(&measure, false);
//  if (measure.RangeStatus != 4)
//  {
//    dis_back = measure.RangeMilliMeter / 10;
//    //         Serial.println(dis_back);
//    //         delay(50);
//  }
//  else dis_back = 150;
//}
