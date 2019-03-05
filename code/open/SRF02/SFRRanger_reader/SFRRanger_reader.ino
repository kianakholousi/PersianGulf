// I2C SRF10 or SRF08 Devantech Ultrasonic Ranger Finder 
// by Nicholas Zambetti <http://www.zambetti.com>
// and James Tichenor <http://www.jamestichenor.net> 

// Demonstrates use of the Wire2 library reading data from the 
// Devantech Utrasonic Rangers SFR08 and SFR10

// Created 29 April 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire2.begin();                // join i2c bus (address optional for master)
  Serial.begin(9600);          // start serial communication at 9600bps
}

int reading = 0;

void loop()
{
  // step 1: instruct sensor to read echoes
  Wire2.beginTransmission(114); // transmit to device #112 (0x70)
                               // the address specified in the datasheet is 224 (0xE0)
                               // but i2c adressing uses the high 7 bits so it's 112
  Wire2.write(byte(0x00));      // sets register pointer to the command register (0x00)  
  Wire2.write(byte(0x51));      // command sensor to measure in "inches" (0x50) 
                               // use 0x51 for centimeters
                               // use 0x52 for ping microseconds
  Wire2.endTransmission();      // stop transmitting

  // step 2: wait for readings to happen
  delay(70);                   // datasheet suggests at least 65 milliseconds

  // step 3: instruct sensor to return a particular echo reading
  Wire2.beginTransmission(114); // transmit to device #112
  Wire2.write(byte(0x02));      // sets register pointer to echo #1 register (0x02)
  Wire2.endTransmission();      // stop transmitting

  // step 4: request reading from sensor
  Wire2.requestFrom(114, 2);    // request 2 bytes from slave device #112

  // step 5: receive reading from sensor
  if (Wire2.available() >= 2) { // if two bytes were received
    reading = Wire2.read();     // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading = Wire2.read();    // receive low byte as lower 8 bits
    Serial.println(reading);   // print the reading
  }

  delay(0);                  // wait a bit since people have to read the output :)
}


/*

// The following code changes the address of a Devantech Ultrasonic Range Finder (SRF10 or SRF08)
// usage: changeAddress(0x70, 0xE6);

void changeAddress(byte oldAddress, byte newAddress)
{
  Wire2.beginTransmission(oldAddress);
  Wire2.write(byte(0x00));
  Wire2.write(byte(0xA0));
  Wire2.endTransmission();

  Wire2.beginTransmission(oldAddress);
  Wire2.write(byte(0x00));
  Wire2.write(byte(0xAA));
  Wire2.endTransmission();

  Wire2.beginTransmission(oldAddress);
  Wire2.write(byte(0x00));
  Wire2.write(byte(0xA5));
  Wire2.endTransmission();

  Wire2.beginTransmission(oldAddress);
  Wire2.write(byte(0x00));
  Wire2.write(newAddress);
  Wire2.endTransmission();
}

*/
