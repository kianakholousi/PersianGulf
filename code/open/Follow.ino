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
        //        Serial.println("HELLO");
        BCounter = 0;
        Bx = pcam.blocks[j].x - 160;
        By = pcam.blocks[j].y - 90;
        if (Bx < 0) BxCenter = Bx - (pcam.blocks[j].width / 2);
        else BxCenter = Bx + (pcam.blocks[j].width / 2);
        if (By < 0) ByCenter = By - (pcam.blocks[j].height / 2);
        else ByCenter = By + (pcam.blocks[j].height / 2);
        Bx = -Bx;
        BxCenter = -BxCenter;
      }

      else if (pcam.blocks[j].signature == 2)////G Yellow
      {

       GYx = pcam.blocks[j].x - 160;
        GYy = pcam.blocks[j].y - 90;
        if (GYx < 0) GYxCenter = GYx - (pcam.blocks[j].width / 2);
        else GYxCenter = GYx + (pcam.blocks[j].width / 2);
        if (GYy < 0) GYyCenter = GYy - (pcam.blocks[j].height / 2);
        else GYyCenter = GYy + (pcam.blocks[j].height / 2);

        //        GYxCenter = abs (GYx) + (pcam.blocks[j].width / 2);
        //        GYyCenter = abs (GYy) + (pcam.blocks[j].height / 2);
        GYx = -GYx;
        DistanceGY = pcam.blocks[j].width;
      }
      //      else if (pcam.blocks[j].signature == 2)////G Blue
      //      {
      //        GBx = pcam.blocks[j].x - 160;
      //        GBy = pcam.blocks[j].y - 97;
      //        GBxCenter = abs (GBx) + (pcam.blocks[j].width / 2);
      //        GByCenter = abs (GBy) + (pcam.blocks[j].height / 2);
      //        GBx = -GBx;
      //        DistanceGB = pcam.blocks[j].width;
      //      }
    }
    //yellow angle
    GYa = atan2(GYy, GYx) * 180 / PI;
    //    if (GYa < 0) GYa = GYa + 360;
    //    if (GYa > 180) GYa = GYa - 360;
    //    if (GYa < 180) GYa = GYa;
    //Blue angle
    GBa = atan2(GBy, GBx) * 180 / PI;
    if (GBa < 0) GBa = GBa + 360;
    //Ball angle
    Ba = atan2(By, Bx) * 180 / PI;
    if (Ba < 0) Ba = Ba + 360;

    //Ball distance
    DistanceB = sqrt((BxCenter * BxCenter) + (ByCenter * ByCenter)) ;
    DShift = 120 - DistanceB;
  }
}
//------------shift-new--------------------------
void shift()
{
  col_ang();

  if (Ba < 120) ba = (atan2(ByCenter, BxCenter - 40) * 180 / PI);
  if (Ba > 240) ba = (atan2(ByCenter, BxCenter - 40) * 180 / PI);

  else if (Ba > 120 && Ba < 180) ba = (atan2(ByCenter - 30, BxCenter) * 180 / PI) + (DShift / 10);
  else if (Ba > 180 && Ba < 240) ba = (atan2(ByCenter + 40, BxCenter) * 180 / PI) + (DShift / 10);

  if (ba < 0) ba = ba + 360;

  if (Ba > 345 || Ba < 15) mot_ang(0);
  else mot_ang(ba);
}
///////////////////////////////////////////
/////////////////////////////////////////////

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
  if (Ri1 == 1 || Ri2 == 1)
  {
    while (Ba > r1 && Ba < l1 && Ball == 1)
    {
      Read_Cmp();
      OS_Comparison();
      OS_Reader();
      col_ang();
      //set_s=-spin_speed(1,50,20);
      if (Ri1 == 1)
      {
        mot_ang(270);
      }
      else if (Fr1 == 1 || Fr2 == 1)
      {
        if (Fr1 == 1) mot_ang(225);
        else if (Fr2 == 1)
        {
          while (Fr1 == 0)
          {
            mot_ang(225);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
            //set_s=spin_speed(1,50,20);
          }
        }
      }
      else if (Ba1 == 1 || Ba2 == 1)
      {
        if (Ba1 == 1) mot_ang(315);
        else if (Ba2 == 1)
        {
          while (Ba1 == 0 )
          {
            mot_ang(315);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();

          }
        }
      }
      else if (Ri2 == 1)
      {
        while (Ri1 == 0)
        {
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
          //set_s=spin_speed(1,50,50);
          mot_ang(270);
        }
      }
      else STOP();
    }
    ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
    if (Ri1 == 1)
    {
      mot_ang(270);
    }
    else if (Fr1 == 1 || Fr2 == 1)
    {
      if (Fr1 == 1) mot_ang(225);
      else if (Fr2 == 1)
      {
        while (Fr1 == 0)
        {
          mot_ang(225);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
          //set_m=spin_speed(1,15,3);
          //set_s=spin_speed(1,50,20);

        }
      }
    }
    else if (Ba1 == 1 || Ba2 == 1)
    {
      if (Ba1 == 1) mot_ang(315);
      else if (Ba2 == 1)
      {
        while (Ba1 == 0 )
        {
          mot_ang(225);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Ri2 == 1)
    {
      while (Ri1 == 0 )
      {
        mot_ang(270);
        Read_Cmp();
        OS_Comparison();
        OS_Reader();
        col_ang();
      }
    }
    else STOP();
  }
  else if (Le1 == 1 || Le2 == 1)
  {
    while (Ba > r2 && Ba < l2 && Ball == 1)
    {
      Read_Cmp();
      OS_Comparison();
      OS_Reader();
      col_ang();
      //set_m=spin_speed(1,15,3);
      //set_s=spin_speed(1,50,20);
      if (Le1 == 1)
      {
        mot_ang(90);
      }
      else if (Fr1 == 1 || Fr2 == 1)
      {
        if (Fr1 == 1) mot_ang(135);
        else if (Fr2 == 1)
        {
          while (Fr1 == 0)
          {
            //set_m=spin_speed(1,15,3);
            //set_s=spin_speed(1,50,20);
            mot_ang(135);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();

          }
        }
      }
      else if (Ba1 == 1 || Ba2 == 1)
      {
        if (Ba1 == 1) mot_ang(45);
        else if (Ba2 == 1)
        {
          while (Ba1 == 0 )
          {
            mot_ang(45);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
          }
        }
      }
      else if (Le2 == 1)
      {
        while (Le1 == 0 )
        {
          //set_m=spin_speed(1,15,3);
          //set_s=spin_speed(1,50,20);
          mot_ang(90);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
      else STOP();
    }
    if (Le1 == 1)
    {
      mot_ang(90);
    }
    else if (Fr1 == 1 || Fr2 == 1)
    {
      if (Fr1 == 1) mot_ang(135);
      else if (Fr2 == 1)
      {
        while (Fr1 == 0)
        {
          mot_ang(135);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Ba1 == 1 || Ba2 == 1)
    {
      if (Ba1 == 1) mot_ang(45);
      else if (Ba2 == 1)
      {
        while (Ba1 == 0 )
        {
          //set_m=spin_speed(1,15,3);
          //                        set_s=spin_speed(1,50,20);
          mot_ang(45);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Le2 == 1)
    {
      while (Le1 == 0)
      {
        //set_m=spin_speed(1,15,3);
        //                    set_s=spin_speed(1,50,20);
        mot_ang(90);
        Read_Cmp();
        OS_Comparison();
        OS_Reader();
        col_ang();
      }
    }
    else STOP();
  }

  else if (Fr1 == 1 || Fr2 == 1)
  {
    while ((Ba > 270 || Ba < 90) && Ball == 1)
    {
      Read_Cmp();
      OS_Comparison();
      OS_Reader();
      col_ang();
      //set_m=spin_speed(1,15,3);
      //set_s=spin_speed(1,50,20);
      if (Fr1 == 1)
      {
        mot_ang(180);
      }
      else if (Ri1 == 1 || Ri2 == 1)
      {
        if (Ri1 == 1) mot_ang(225);
        else if (Ri2 == 1)
        {
          while (Ri1 == 0 )
          {
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
            mot_ang(225);
          }
        }
      }
      else if (Le1 == 1 || Le2 == 1)
      {
        if (Le1 == 1) mot_ang(135);
        else if (Le2 == 1)
        {
          while (Le1 == 0)
          {
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
            mot_ang(135);
          }
        }
      }
      else if (Fr2 == 1)
      {
        while (Fr1 == 0)
        {
          mot_ang(180);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
      else STOP();
    }
    if (Fr1 == 1)
    {
      mot_ang(180);
    }
    else if (Ri1 == 1 || Ri2 == 1)
    {
      if (Ri1 == 1) mot_ang(225);
      else if (Ri2 == 1)
      {
        while (Ri1 == 0)
        {
          mot_ang(225);
          mot_ang(180);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Le1 == 1 || Le2 == 1)
    {
      if (Le1 == 1) mot_ang(135);
      else if (Le2 == 1)
      {
        while (Le1 == 0)
        {
          mot_ang(135);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Fr2 == 1)
    {
      while (Fr1 == 0)
      {
        mot_ang(180);
        Read_Cmp();
        OS_Comparison();
        OS_Reader();
        col_ang();
      }
    }
    else STOP();
  }

  else if (Ba1 == 1 || Ba2 == 1)
  {
    while (Ba < 270 && Ba > 90 && Ball == 1)
    {
      Read_Cmp();
      OS_Comparison();
      OS_Reader();
      col_ang();
      //set_m=spin_speed(1,15,3);
      //set_s=spin_speed(1,50,50);
      if (Ba1 == 1)
      {
        mot_ang(0);
        //        mamadagha = 1;
      }
      else if (Ri1 == 1 || Ri2 == 1)
      {
        if (Ri1 == 1) mot_ang(315);
        else if (Ri2 == 1)
        {
          while (Ri1 == 0 )
          {
            //set_m=spin_speed(1,15,3);
            //set_s=spin_speed(1,50,20);
            mot_ang(315);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
          }
        }
      }
      else if (Le1 == 1 || Le2 == 1)
      {
        if (Le1 == 1) mot_ang(45);
        else if (Le2 == 1)
        {
          while (Le1 == 0 )
          {
            //set_m=spin_speed(1,15,3);
            //set_s=spin_speed(1,50,20);
            mot_ang(45);
            Read_Cmp();
            OS_Comparison();
            OS_Reader();
            col_ang();
          }
        }
      }
      else if (Ba2 == 1)
      {
        while (Ba1 == 0)
        {
          //set_m=spin_speed(1,15,3);
          //set_s=spin_speed(1,50,20);
          mot_ang(0);
          //          mamadagha = 2;
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
      else STOP();
    }
    if (Ba1 == 1)
    {
      mot_ang(0);
      //      mamadagha = 3;
    }
    else if (Ri1 == 1 || Ri2 == 1)
    {
      if (Ri1 == 1) mot_ang(315);
      else if (Ri2 == 1)
      {
        while (Ri1 == 0)
        {
          //set_m=spin_speed(1,15,3);
          //set_s=spin_speed(1,50,20);
          mot_ang(315);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Le1 == 1 || Le2 == 1)
    {
      if (Le1 == 1) mot_ang(45);
      else if (Le2 == 1)
      {
        while (Le1 == 0)
        {
          //set_m=spin_speed(1,15,3);
          //set_s=spin_speed(1,50,50);
          mot_ang(45);
          Read_Cmp();
          OS_Comparison();
          OS_Reader();
          col_ang();
        }
      }
    }
    else if (Ba2 == 1)
    {
      while (Ba1 == 0)
      {
        //set_m=spin_speed(1,15,3);
        //set_s=spin_speed(1,50,20);
        mot_ang(0);
        Read_Cmp();
        OS_Comparison();
        OS_Reader();
        col_ang();
      }
    }
    else STOP();
  }
  else
  {
    if (Ball == 1)
    {
      shift();
      Do_Shoot();
    }
    else STOP();
  }
}
//------------STOP------------
void STOP()
{ reduction = 1;
  MOTOR (0 + set_s, 0 + set_s , 0 + set_s , 0 + set_s);
}
//////////////////////////////

//------------Shoot------------
void Do_Shoot()
{
  if ((Ba <= 8 || Ba >= 355) && (DistanceB <= 9) && Ball == 1 && Shootflag == 1)
  {
    digitalWrite(Shoot, HIGH);
    delay(15);
    digitalWrite(Shoot, LOW);
    ShootCounter = 0;
  }
}
