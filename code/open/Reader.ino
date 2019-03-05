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
//  Serial.println(Cmp);
//  delay(50);
}
//------------reading BNO055----------
void Read_bno()
{
  uint8_t system, gyro, accel, mag;
  system = gyro = accel = mag = 0;
  bno.getEvent(&event);
  bno.getCalibration(&system, &gyro, &accel, &mag);
  //----------BNO---calibration
  //  Serial.print("Sys:");
  //  Serial.print(system, DEC);
  //  Serial.print(" G:");
  //  Serial.print(gyro, DEC);
  //  Serial.print(" A:");
  //  Serial.print(accel, DEC);
  //  Serial.print(" M:");
  //  Serial.print(mag, DEC);
  //  Serial.print("\t");
  if (bno.isFullyCalibrated() && Calibrate_BNO == 0)
  {
    bno.getSensorOffsets(newCalib);
    EEPROM.put(eeAddress, newCalib);
    Serial.println("Calibrated");
    Calibrate_BNO = 1;
    delay(1000);
  }
  else
  {
    bnox = event.orientation.x;
  }
  bnox = map(bnox, 0, 360, 0, 1023);
  if (bnox - setcmp < 0) Cmp = 1023 - (setcmp - bnox);
  else  Cmp = bnox - setcmp;
  if (Cmp > 512) Cmp = Cmp - 1023;


}
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
    distance = Wire2.read();     // receive high byte (overwrites previous reading)
    distance = distance << 8;    // shift high byte to be high 8 bits
    distance = Wire2.read();    // receive low byte as lower 8 bits
    //    Serial.print(distance);
  }

}
//------------VL53L0X_d----------------
void VL_Reader()
{
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4)
  {
    distance = measure.RangeMilliMeter / 10;
    //         Serial.println(distance);
    //         delay(50);
  }
  else distance = 150;
}
