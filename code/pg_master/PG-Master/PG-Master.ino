void setup() {
  //------------VL53L0X_d----------------
  //  lox.begin();
  //------------start_robot--------------
  //  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  //  Serial5.begin(9600);
  analogWriteResolution(10);
  //  pcam.init();
  //  Wire2.begin();
  set_pins();
  //  eeprom_read();
  //------------bBNO055-----------------
  //  bno.begin();
  //  EEPROM.get(eeAddress, calibrationData);
  //  bno.setSensorOffsets(calibrationData);
  //  bno.setExtCrystalUse(true);
  //    bno.getSensorOffsets(newCalib);
}

void loop() {
  reduction = 0.6;
  mot_ang(0);
}
