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


  while (1) 
  {
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
