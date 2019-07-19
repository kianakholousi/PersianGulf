void Read_Cmp()
{
  Wire.beginTransmission(address);  ////starts communication with cmp03
  Wire.write(2);                    /////sends the register we wish to read
  Wire.endTransmission();
  Wire.requestFrom(address, 2);
  //  while(Wire.available() < 2);
  Compass2 = Wire.read() << 8 | Wire.read();
  Wire.endTransmission();
  Compass = map(Compass2, 0, 3600, 0, 1023);

  //////baze bandii
  int b, a;
  a = Compass - setcmp;
  if (a > 0) b = a;
  else b = a + 1023;
  if (b > 512) b = b - 1023;
  else b = b;
  Cmp = -b;
}

//------------reading BNO055----------
void SRF_Reader()
{
  Wire.beginTransmission(113); // transmit to device #112 (0x70)
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c adressing uses the high 7 bits so it's 112
  Wire.write(byte(0x00));      // sets register pointer to the command register (0x00)
  Wire.write(byte(0x51));      // command sensor to measure in "CENTIMETERS" (0x51)
  // use 0x50 for inches
  // use 0x52 for ping microseconds
  Wire.endTransmission();      // stop transmitting

  // step 2: wait for readings to happen
  delay(70);                   // datasheet suggests at least 65 milliseconds

  // step 3: instruct sensor to return a particular echo reading
  Wire.beginTransmission(113); // transmit to device #112
  Wire.write(byte(0x02));      // sets register pointer to echo #1 register (0x02)
  Wire.endTransmission();      // stop transmitting

  // step 4: request reading from sensor
  Wire.requestFrom(113, 2);    // request 2 bytes from slave device #113

  // step 5: receive reading from sensor
  if (Wire.available() >= 2) { // if two bytes were received
    dis_back = Wire.read();     // receive high byte (overwrites previous reading)
    dis_back = dis_back << 8;    // shift high byte to be high 8 bits
    dis_back = Wire.read();    // receive low byte as lower 8 bits
    //Serial.print(dis_back);
  }
}
//------------VL53L0X_d----------------
void VL_Reader()
{
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4)
  {
    dis_back = measure.RangeMilliMeter ;
//    Serial.println(dis_back);
//    delay(50);
  }
  else dis_back = 1500;
}

//------reading out sensors----
void OS_Reader()
{
  FO = analogRead(36);
  FI = analogRead(37);
  RO = analogRead(34);
  RI = analogRead(33);
  LO = analogRead(A21);
  LI = analogRead(A22);
  BO = analogRead(18);
  BI = analogRead(19);
}

////////////////////outsensors///////////////////
void OC()
{
  OS_Reader();
  if (FO > NFO) fa = 1;
  else fa = 0;
  if (FI > NFI ) fb = 1;
  else fb = 0;
  if (RO > NRO) ra = 1;
  else ra = 0;
  if ( RI > NRI) rb = 1;
  else rb = 0;
  if (LO > NLO) la = 1;
  else la = 0;
  if ( LI > NLI) lb = 1;
  else lb = 0;
  if ( BO > NBO) ba = 1;
  else ba = 0;
  if (BI > NBI)  bb = 1;
  else bb = 0;
//
//  if (fa || fb) digitalWrite(14, HIGH);
//  else digitalWrite(14, LOW);
//  if (ra || rb) digitalWrite(15, HIGH);
//  else digitalWrite(15, LOW);
//  if (ba || bb) digitalWrite(16, HIGH);
//  else digitalWrite(16, LOW);
//  if (la || lb) digitalWrite(17, HIGH);
//  else digitalWrite(17, LOW);

}

///////////////////////////////////////////////////

void Calibration()
{
  byte highByte;
  byte lowByte;
  Serial.println("north");
  delay(5000);
  Wire.beginTransmission(address);//starts communication with cmps03
  Wire.write(15); //Sends the register we wish to read
  Wire.write(byte(0xFF));
  Wire.endTransmission();
  Serial.println("east");
  delay(5000);
  Wire.beginTransmission(address);
  Wire.write(15);
  Wire.write(byte(0xFF)); //Sends the register we wish to read
  Wire.endTransmission();
  Serial.println("south");
  delay(5000);
  Wire.beginTransmission(address);
  Wire.write(15);
  Wire.write(byte(0xFF)); //Sends the register we wish to read
  Wire.endTransmission();
  Serial.println("west");
  delay(5000);
  Wire.beginTransmission(address);
  Wire.write(15);
  Wire.write(byte(0xFF)); //Sends the register we wish to read
  Wire.endTransmission();
  while (1)
  {
    Wire.beginTransmission(address);
    Wire.write(1);
    Wire.endTransmission();
    Wire.requestFrom(address, 2);        //requests high byte
    highByte = Wire.read();           //reads the byte as an integer
    int bearing = highByte;
    Serial.println(bearing);
    delay(100);
  }
}

//////////////////////////////////
