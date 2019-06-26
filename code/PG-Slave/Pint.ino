
void set_pins()
{
  //------------MOTORS-------------------
  pinMode(21, OUTPUT);//pwm mlf
  pinMode(23, OUTPUT);//pwm mlb
  pinMode(6, OUTPUT);//pwm mrb
  pinMode(10, OUTPUT);//pwm mrf
  pinMode(20,  OUTPUT);//GPIO mlf
  pinMode(22,  OUTPUT);//GPIO mlb
  pinMode(5,  OUTPUT);//GPIO mrb
  pinMode(9,  OUTPUT);//GPIO mrf
  analogWriteResolution(10);
  analogWriteFrequency(21, 29296.875);
  //------------out sensors---------------
  pinMode(37, INPUT);//FI
  pinMode(36, INPUT);//FO
  pinMode(33, INPUT);//RI
  pinMode(34, INPUT);//RO
  pinMode(A22, INPUT);//LI
  pinMode(A21, INPUT);//LO
  pinMode(19, INPUT);//BI
  pinMode(18, INPUT);//BO
  //------------shoot---------------------
  pinMode(Shoot, OUTPUT);
  //------------battery feedback----------
  pinMode(32, INPUT);
  pinMode(14, OUTPUT);//LED
  pinMode(15, OUTPUT);//LED
  pinMode(16, OUTPUT);//LED
  pinMode(17, OUTPUT);//LED
  //------------DIP switch-----------------
  pinMode(38, INPUT);
  pinMode(39, INPUT);
  //------------Buzzer--------------------
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  delay(35);
  digitalWrite(11, LOW);
  pinMode(29, OUTPUT);
}
