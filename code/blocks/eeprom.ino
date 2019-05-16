void eeprom_write()
{
    EEPROM.write(0, highByte(setcmp));  EEPROM.write(1, lowByte(setcmp));
    EEPROM.write(2, highByte(OSP[1]));  EEPROM.write(3, lowByte(OSP[1]));
    EEPROM.write(4, highByte(OSP[2]));  EEPROM.write(5, lowByte(OSP[2]));
    EEPROM.write(6, highByte(OSP[3]));  EEPROM.write(7, lowByte(OSP[3]));
    EEPROM.write(8, highByte(OSP[4]));  EEPROM.write(9, lowByte(OSP[4]));
    EEPROM.write(10, highByte(OSP[5])); EEPROM.write(11, lowByte(OSP[5]));
    EEPROM.write(12, highByte(OSP[6])); EEPROM.write(13, lowByte(OSP[6]));
    EEPROM.write(14, highByte(OSP[7])); EEPROM.write(15, lowByte(OSP[7]));
    EEPROM.write(16, highByte(OSP[8])); EEPROM.write(17, lowByte(OSP[8]));
}

void eeprom_read()
{
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
