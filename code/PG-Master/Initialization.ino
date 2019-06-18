void SET() {
  if (digitalRead(29) == LOW)
  {
    while (digitalRead(29) == LOW)
    {
      digitalWrite(21, HIGH);
      //------------set out sensors on green
      FO = analogRead(49); //F1
      FI = analogRead(32); //F2
      RO = analogRead(23); //R1
      RI = analogRead(22); //R2
      LO = analogRead(18); //L1
      LI = analogRead(19); //L2
      BO = analogRead(16); //B1
      BI = analogRead(17); //B2
      Read_Cmp();
      //      Read_bno();
    }
    //      setcmp = bnox;
    setcmp = Compass;
    NFO = FO + 45;
    NFI = FI + 50;
    NRO = RO + 35;
    NRI = RI + 45;
    NLO = LO + 35;
    NLI = LI + 45;
    NBO = BO + 40;
    NBI = BI + 50;
    eeprom_write();
    digitalWrite(21, LOW);
  }
}

//------------INTER_UP_T---------------------
void Counter()
{
  reduction = 0.9;
  BC++;
  if (south) {
    flag = 0;
    set_s = spin_speed(1, 30, 10);
  }
  else {
    flag = 1;
    set_s = spin_speed(1, 30, 40);
  }
  if (BC > 2) Ball = false;
  else Ball = true;
}

//------------spin speed------------
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  if (flag == 0) {
    Read_Cmp();
    compass_input = Cmp ;
  }
  if (flag == 1) {
    col_ang();
    compass_input = GYa;
  }
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value * 1.5);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;
}
