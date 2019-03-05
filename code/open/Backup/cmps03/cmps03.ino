#include <Wire.h>
int Compass = 0;
void setup() 
{
  Wire2.begin();
  Serial.begin(9600);
}

void loop() 
{
  Wire2.beginTransmission(96);  ////starts communication with cmp03
  Wire2.write(1);                    /////sends the register we wish to read
  Wire2.endTransmission();
  Wire2.requestFrom(96, 1);     /////requests high byte
  Compass = Wire2.read();
  Wire2.endTransmission();
  Serial.println(Compass);
  delay(1);
}
