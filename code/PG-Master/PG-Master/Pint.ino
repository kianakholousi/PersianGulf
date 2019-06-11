
void set_pins()
{
  //------------MOTORS-------------------
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(7,  OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(2,  OUTPUT);
  pinMode(8,  OUTPUT);
  analogWriteResolution(10);
  analogWriteFrequency(38, 29296.875);
  //------------out sensors---------------
  pinMode(49, INPUT);//49
  pinMode(32, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  //------------shoot---------------------
  pinMode(Shoot, OUTPUT);
  //------------battery feedback----------
  pinMode(20, INPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  //------------DIP switch-----------------
  pinMode(36, INPUT);
  pinMode(35, INPUT);
  pinMode(15, INPUT);
  //------------Buzzer--------------------
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  delay(50);
  digitalWrite(21, LOW);
  delay(30);
  digitalWrite(21, HIGH);
  delay(50);
  digitalWrite(21, LOW);
  pinMode(29, INPUT);
}
