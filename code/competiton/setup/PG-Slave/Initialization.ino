void SET() {
  if (digitalRead(35) == LOW)
  {

    while (digitalRead(35) == LOW)
    {
      digitalWrite(11, HIGH);
      ////------------set out sensors on green
      Read_Cmp();
      ////    Read_bno();
    }
    //  setcmp = bnox;
    setcmp = Compass;
    NFO = FO + 90;
    NFI = FI + 100;
    NRO = RO + 60;
    NRI = RI + 90;
    NLO = LO + 130;
    NLI = LI + 130;
    NBO = BO + 80;
    NBI = BI + 100;
    eeprom_write();
    digitalWrite(11, LOW);
  }
}

void Bazi() {
  Compass2 = Compass2 / 10;
  if (yell > 180) yell = yell - 360;
  if (Compass2 > 180) Compass2 = Compass2 - 360;
}
//------------spin speed------------
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
//  

  if (flag == 0) {
    Read_Cmp();
    compass_input = Cmp;
  }
  if (flag == 1) {
    col_ang();
    compass_input = GYa;
  }
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;

}
