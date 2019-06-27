
void MOTOR(int lf, int lb, int rf, int rb)
{
  if (lf > 1023)  lf = 1023;
  if (lf < -1023) lf = -1023;
  if (lb > 1023)  lb = 1023;
  if (lb < -1023) lb = -1023;
  if (rb > 1023)  rb = 1023;

  if (rb < -1023) rb = -1023;
  if (rf > 1023)  rf = 1023;
  if (rf < -1023) rf = -1023;

  lf = lf * reduction  * -1;
  lb = lb * reduction  * 1;
  rf = rf * reduction  * -1;
  rb = rb * reduction  * -1;
  ////////LF
  if (lf < 0)
  {
    analogWrite( PWMlf, 1023 + lf  );
    digitalWrite(digitalPINlf, HIGH);
  }
  else if (lf > 0)
  {
    analogWrite( PWMlf, lf);
    digitalWrite(digitalPINlf, LOW);
  }
  else if (lf == 0)
  {
    analogWrite( PWMlf, 0 );
    digitalWrite(digitalPINlf, LOW);
  }
  //////lb
  if (lb < 0)
  {
    analogWrite( PWMlb, 1023 + lb );
    digitalWrite(digitalPINlb, HIGH);
  }
  else if (lb > 0)
  {
    analogWrite( PWMlb, lb );
    digitalWrite(digitalPINlb, LOW);
  }

  else if (lb == 0)
  {
    analogWrite( PWMlb, 0 );
    digitalWrite(digitalPINlb, LOW);
  }
  ///////rb
  if (rb < 0)
  {
    analogWrite( PWMrb, rb + 1023 );
    digitalWrite(digitalPINrb, HIGH);
  }
  else if (rb > 0)
  {
    analogWrite( PWMrb, rb);
    digitalWrite(digitalPINrb, LOW);
  }
  else if (rb == 0)
  {
    analogWrite( PWMrb, 0 );
    digitalWrite(digitalPINrb, LOW);
  }
  ///////rf
  if (rf < 0)
  {
    analogWrite( PWMrf, (rf  + 1023));
    digitalWrite(digitalPINrf, HIGH);
  }
  else if (rf > 0)
  {
    analogWrite( PWMrf, rf );
    digitalWrite(digitalPINrf, LOW);
  }
  else if (rf == 0) {
    analogWrite( PWMrf, 0 );
    digitalWrite(digitalPINrf, LOW);
  }
}

void mot_ang(float ang)
{
  float division = 1023 / 45;
  int lf;
  int lb;
  int rb;
  int rf;
  if (0 <= ang && ang < 90) {
    lf = -1023;
    lb = -1023 + (ang * division);
    rf = 1023 - (ang * division);
    rb = 1023;
  }
  else if (90 <= ang && ang < 180) {
    ang = ang - 90;
    lf = -1023 + (ang * division);
    lb = 1023;
    rf = -1023;
    rb = 1024 - (ang * division);
  }
  else if (180 <= ang && ang < 270)
  {
    ang = ang - 180;
    lf = 1023;
    lb = 1023 - (ang * division);
    rf = -1023 + (ang * division);
    rb = -1023;
  }
  else if (270 <= ang && ang <= 360) {
    ang = ang - 270;
    lf = 1023 - (ang * division);
    lb = -1023;
    rf = 1023;
    rb = -1024 + (ang * division);
  }
  MOTOR (lf + set_s, lb + set_s, rf + set_s, rb + set_s);
}
void MOVE(float ang)
{
  float division = 512 / 22.5;
  int lf = 0;
  int lb = 0;
  int rb = 0;
  int rf = 0;
  if (0 <= ang && ang < 90) {
    lf = 1023;
    lb = 1024 - (ang * division);
    rb = -1023;
    rf = -1024 + (ang * division);
  }
  else if (90 <= ang && ang < 180) {
    ang = ang - 90;
    lf = 1024 - (ang * division);
    lb = -1024;
    rb = -1024 + (ang * division);
    rf = 1024;
  }
  else if (180 <= ang && ang < 270)
  {
    ang = ang - 180;
    lf = -1023;
    lb = -1024 + (ang * division);
    rb = 1023;
    rf = 1024 - (ang * division);
  }
  else if (270 <= ang && ang <= 360) {
    ang = ang - 270;
    lf = -1024 + (ang * division);
    lb = 1023;
    rb = 1024 - (ang * division);
    rf = -1023;
  }
  MOTOR (lf , lb , rf , rb );
}
void shift()
{
//  Bx = -Bx;
  col_ang();
  if (Ba > 345 || Ba <= 15) shif = 0;
  else if (Ba <= 120) shif = (atan2(By, Bx - 25) * 180 / PI)  + (DShift / 10);
  else if (Ba >= 240) shif = (atan2(By , Bx - 25) * 180 / PI) - (DShift / 10);
  else if (Ba > 120 && Ba <= 180) shif = (atan2(By - 40, Bx) * 180 / PI) - (DShift / 12);
  else if (Ba > 180 && Ba < 240) shif = (atan2(By + 40, Bx) * 180 / PI) + (DShift / 12);
  if (shif < 0) shif = shif + 360;
  mot_ang(shif);
}

//------------STOP------------
void STOP()
{
  reduction = 1;
  MOTOR (0 + set_s, 0 + set_s , 0 + set_s , 0 + set_s);
}

void Shut()
{
  if ((Ba <= 8 || Ba >= 355) && (DistanceB <= 9) && Ball == 1 && Shootflag == 1)
  {
    digitalWrite(Shoot, HIGH);
    delay(15);
    digitalWrite(Shoot, LOW);
    SHC = 0;
  }
}
void harekat_vazi_mah() {
  for (int i = 0; i <= 360; i++)
  {
    mot_ang(i);
    delay(5);
  }
}
