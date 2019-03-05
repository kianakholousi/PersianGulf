//154 94 ghalate
//154 102 doroste
//------------motors------------
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
  rf = rf * reduction  * -1;
  lb = lb * reduction  * -1;
  rb = rb * reduction  * -1;
  ////////LF
  if (lf < 0)
  {

    analogWrite( PWMlf, 1023 + lf * 0.98 );
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
    analogWrite( PWMlb, 1023 + lb * 0.98);
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
    analogWrite( PWMrb, rb * 0.98 + 1023 );
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
    analogWrite( PWMrf, (rf * 0.98 + 1023));
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
//------------color to angle------------
void col_ang()
{
  uint16_t blocks;
  blocks = pcam.getBlocks();
  if (blocks)
  {
    for (int j = 0; j < blocks; j++)
    {
      if (pcam.blocks[j].signature == 1)
      {
        BCounter = 0;
        Bx = pcam.blocks[j].x - 161;
        By = pcam.blocks[j].y - 103;
        BxCenter = abs (Bx) + (pcam.blocks[j].width / 2);
        ByCenter = abs (By) + (pcam.blocks[j].height / 2);
        Bx=-Bx;
      }

      else if (pcam.blocks[j].signature == 3)////G Yellow
      {
        GYx = pcam.blocks[j].x - 161;
        GYy = pcam.blocks[j].y - 103;
        GYxCenter = abs (GYx) + (pcam.blocks[j].width / 2);
        GYyCenter = abs (GYy) + (pcam.blocks[j].height / 2);
        GYx = -GYx; 
        DistanceGY = pcam.blocks[j].width;
      }
      else if (pcam.blocks[j].signature == 2)////G Blue
      {
        GBx = pcam.blocks[j].x - 161;
        GBy = pcam.blocks[j].y - 103;
        GBxCenter = abs (GBx) + (pcam.blocks[j].width / 2);
        GByCenter = abs (GBy) + (pcam.blocks[j].height / 2);
        GBx = -GBx;
        DistanceGB = pcam.blocks[j].width;
      }
    }
    //yellow angle 
    GYa = atan2(GYy, GYx) * 180 / PI;
    if (GYa < 0) GYa = GYa + 360;
    //Blue angle
    GBa = atan2(GBy, GBx) * 180 / PI;
    if (GBa < 0) GBa = GBa + 360;
    //Ball angle 
    Ba = atan2(By, Bx) * 180 / PI;
    if (Ba < 0) Ba = Ba + 360;
    //Ball distance   
    DistanceB = sqrt(BxCenter * BxCenter + ByCenter * ByCenter)-38;
  }
 }
//------------shift------------
void shift()
{
    col_ang();
   int zarib;
     float factor;
  if (Ba>320 || Ba<40) zarib=50;
  else zarib=130;
  if (Ba > 15 &&  Ba <= 180)
  {
    factor = Ba + (zarib * 10 / (DistanceB));
  }
  else if (Ba > 180 && Ba <= 345)
  {
    factor = Ba - (zarib * 10 / DistanceB);
  }
  else factor = 0;
  
  mot_ang( factor);
}
//------------angle to motors------------
void mot_ang(float ang)
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

  MOTOR (lf + set_s, lb + set_s, rf + set_s, rb + set_s);
}

//------------follow ba out------------
void fol_out()
{
//------------Right masmal------
//  if (Ri1 == 1 && Ba > 180)
//  {
//    while (Ba >= 155)
//    {
//      Read_Cmp();
//      OS_Reader();
//      col_ang();
//      set_s = -spin_speed(1, 50, 50);
//      reduction = 0.4;
//      mot_ang(270);
//    }
//  }
//
//------------left masmal-------
//  if (Le1 == 1 && Ba < 180 )
//  {
//    while (Ba <= 205)
//    {
//      Read_Cmp();
//      OS_Reader();
//      col_ang();
//      set_s = -spin_speed(1, 50, 50);
//      reduction = 0.4;
//      mot_ang(90);
//    }
//  }
//------------RIGHT--------------
 if ((Ri1 == 1 || Ri2 == 1))
  {
//    if(Fr1==1 ||Fr2==1)
//    {
//    if (Fr1==1)
//    {
//      while(Fr1==1 )
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
//                set_s= -spin_speed(1,50, 20);
//// set_s= -spin_yellow(12);
//        mot_ang(225);
//      }
//    }
//    else if (Fr2==1)
//    {
//      while (Fr1==0)
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
////       set_s= -spin_yellow(12);
//                set_s= -spin_speed(1,50, 20);
//        mot_ang(225);
//      }
//    }
//    }
//   else if(Ba1==1 ||Ba2==1)
//    {
//    if (Ba1==1)
//    {
//      while(Ba1==1 )
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
////                 set_s= -spin_yellow(12);
//                set_s= -spin_speed(1,50, 20);
//        mot_ang(135);
//      }
//    }
//    else if (Ba2==1)
//    {
//      while (Ba1==0)
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
//                set_s= -spin_speed(1,50, 20);
//// set_s= -spin_yellow(12);
//        mot_ang(135);
//      }
//    }
//    }
    
    while (Ba > 0 && Ba < 180 && Ball==1)
    {
      Read_Cmp();
      OS_Comparison();
      col_ang();
      OS_Reader();
      if (Ri1 == 1)
      {
        mot_ang(270);
          set_s= -spin_speed(1,50, 20);
//          set_s= -spin_yellow(12);
      }
      else if (Ri2 == 1)
      {
        while (Ri1 == 0)
        {
          Read_Cmp();
          OS_Comparison();
          mot_ang(270);
          OS_Reader();
        }
      }
      else STOP();
      set_s = -spin_speed(1,50, 20);
//        set_s= -spin_yellow(12);
    }
  }
//------------LEFT------------
  else if ((Le1 == 1 || Le2 == 1))
  {
//    if(Fr1==1 ||Fr2==1)
//    {
//    if (Fr1==1)
//    {
//      while(Fr1==1 )
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
//                set_s= -spin_speed(1,50, 20);
////                  set_s= -spin_yellow(12);
//        mot_ang(315);
//      }
//    }
//    else if (Fr2==1)
//    {
//      while (Fr1==0)
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader(); 
////      set_s= -spin_yellow(12);
//                      set_s= -spin_speed(1,50, 20);
//        mot_ang(315);
//      }
//    }
//    }
//   else if(Ba1==1 ||Ba2==1)
//    {
//    if (Ba1==1)
//    {
//      while(Ba1==1 )
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
////       set_s= -spin_yellow(12);
//                set_s= -spin_speed(1,50, 20);
//        mot_ang(45);
//      }
//    }
//    else if (Ba2==1)
//    {
//      while (Ba1==0)
//      {
//      Read_Cmp();
//      OS_Comparison();
//      col_ang();
//      OS_Reader();
////       set_s= -spin_yellow(12);
//                set_s= -spin_speed(1,50, 20);
//        mot_ang(45);
//      }
//    }
//    }
    while (Ba > 180 && Ba < 360 && Ball==1)
    {
      Read_Cmp();
      col_ang();
      OS_Reader();
      OS_Comparison();
      if (Le1 == 1)
      {
        mot_ang(90);
        set_s = -spin_speed(1, 50, 20);
//        set_s= -spin_yellow(12);
      }
      else if (Le2 == 1)
      {
        while (Le1 == 0)
        {
          Read_Cmp();
          mot_ang(90);
          OS_Reader();
          OS_Comparison();
        }
      }
      else STOP();
      set_s = -spin_speed(1,50, 20);
//        set_s= -spin_yellow(12);
    }
  }

//------------FRONT------------
  else if ((Fr1 == 1 || Fr2 == 1))
  {
    while ((Ba > 270 || Ba < 90) && Ball==1)
    {
      Read_Cmp();
      col_ang();
      OS_Reader();
      OS_Comparison();
      if (Fr1 == 1)
      {
        mot_ang(180);
        set_s = -spin_speed(1,50, 20);
//        set_s= -spin_yellow(12);
      }
      else if (Fr2 == 1)
      {
        while (Fr1 == 0)
        {
          Read_Cmp();
          mot_ang(180);
          OS_Reader();
          OS_Comparison();
        }
      }
      else STOP();
      set_s = -spin_speed(1, 50, 20);
//        set_s= -spin_yellow(12);
    }
  }
//------------BACK------------
  else if ((Ba1 == 1 || Ba2 == 1))
  {
    while (Ba > 90 && Ba < 270 && Ball==1)
    {
      Read_Cmp();
      col_ang();
      OS_Reader();
      OS_Comparison();
      if (Ba1 == 1)
      {
        mot_ang(0);
        set_s = -spin_speed(1,50, 20);
//        set_s= -spin_yellow(12);
      }
      else if (Ba2 == 1)
      {
        while (Ba1 == 0)
        {
          Read_Cmp();
          mot_ang(0);
          OS_Reader();
          OS_Comparison();
        }
      }
      else STOP();
      set_s = -spin_speed(1,50, 20);
//        set_s= -spin_yellow(12);
    }
  }
  else shift();
}
//------------STOP------------
void STOP()
{
  MOTOR (0 + set_s, 0 + set_s , 0 + set_s , 0 + set_s );
}
//------------Shoot------------
void Do_Shoot()
{
    if ((Ba <= 8 || Ba >= 355) && (DistanceB <= 5) && Ball==1 && Shootflag==1)
  {
    digitalWrite(Shoot, HIGH);
    delay(15);
    digitalWrite(Shoot, LOW);
    ShootCounter=0;
  }
}
