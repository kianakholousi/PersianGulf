
void eeprom_write()
{
  EEPROM.write(0, highByte(setcmp));  EEPROM.write(1, lowByte(setcmp));
  EEPROM.write(2, highByte(NFO));  EEPROM.write(3, lowByte(NFO));
  EEPROM.write(4, highByte(NFI));  EEPROM.write(5, lowByte(NFI));
  EEPROM.write(6, highByte(NRO));  EEPROM.write(7, lowByte(NRO));
  EEPROM.write(8, highByte(NRI));  EEPROM.write(9, lowByte(NRI));
  EEPROM.write(10, highByte(NLO)); EEPROM.write(11, lowByte(NLO));
  EEPROM.write(12, highByte(NLI)); EEPROM.write(13, lowByte(NLI));
  EEPROM.write(14, highByte(NBO)); EEPROM.write(15, lowByte(NBO));
  EEPROM.write(16, highByte(NBI)); EEPROM.write(17, lowByte(NBI));
}

void eeprom_read()
{
  setcmp = (EEPROM.read(0)  << 8) | EEPROM.read(1);
  NFO = (EEPROM.read(2)  << 8) | EEPROM.read(3);
  NFI = (EEPROM.read(4)  << 8) | EEPROM.read(5);
  NRO = (EEPROM.read(6)  << 8) | EEPROM.read(7);
  NRI = (EEPROM.read(8)  << 8) | EEPROM.read(9);
  NLO = (EEPROM.read(10) << 8) | EEPROM.read(11);
  NLI = (EEPROM.read(12) << 8) | EEPROM.read(13);
  NBO = (EEPROM.read(14) << 8) | EEPROM.read(15);
  NBI = (EEPROM.read(16) << 8) | EEPROM.read(17);
}
