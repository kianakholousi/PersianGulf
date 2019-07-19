

void SET() {
  if (digitalRead(35) == LOW)
  {

    while (digitalRead(35) == LOW)
    {
      digitalWrite(11, HIGH);
      ////------------set out sensors on green
    FO = analogRead(36);
    FI = analogRead(37);
    RO = analogRead(34);
    RI = analogRead(33);
    LO = analogRead(A21);
    LI = analogRead(A22);
    BO = analogRead(18);
    BI = analogRead(19);
      Read_Cmp();
      ////    Read_bno();
    }
    //  setcmp = bnox;+++
    setcmp = Compass;
    NFO = FO + 90;
    NFI = FI + 100;
    NRO = RO + 70;
    NRI = RI + 40;
    NLO = LO + 80;
    NLI = LI + 85;
    NBO = BO + 40;
    NBI = BI + 55;
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
