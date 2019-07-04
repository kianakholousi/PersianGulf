int LBa = 0, RBa = 0;
//------------backtogoal with yellow------------
void Backtogoal()
{
  digitalWrite(15, HIGH);
  digitalWrite(14, LOW);
  reduction = 0.5;
  VL_Reader();
  col_ang();
  if (abs(Cmp) <= 20)
  {
<<<<<<< HEAD
    if (dis_back < 300)
=======
    if (dis_back < 250)
>>>>>>> 4ee63fefac41ef71876d47e100f2660e9287e27a
      mot_ang(0);
    else if (dis_back > 500 || Gy360 > 190 || Gy360 < 130)
      mot_ang(Gy360);
    else MoveWidth_vl();
  }
  else STOP();
}

//------------move in width with yellow------------
void MoveWidth()
{
  reduction = 0.5;
  if (abs(Cmp) <= 50)
  {
    if (DistanceGY > 30 && DistanceGY < 45 && GYa > 145 && GYa < 210 )
    {
      if (DistanceB > 100)
      {
        RBa = 350;
        LBa = 15;
      }
      else
      {
        RBa = 335;
        LBa = 25;
      }

      if (Ba > LBa && Ba < 90)
      {
        mot_ang(90);
      }
      else if (Ba > 270 && Ba < RBa)
      {
        mot_ang(270);
      }
      else STOP();
    }
    else if ((DistanceGY < 30 || DistanceGY > 45) && (GYa > 210 || GYa < 145) )
    {
      Backtogoal();
    }
  }
  else STOP();
}
//------------backtogoal with VL53L0X------------
void Backtogoal_vl()
{
  VL_Reader();
  col_ang();
  reduction = 0.7;
  if (abs(Cmp) <= 20)
  {
    if (dis_back > 250 && dis_back < 400 /*&  (GYa < 15 || GYa > 345)*/) STOP();
    else if ((dis_back < 250 || dis_back > 400) /*|| (GYa > 15 && GYa < 345)*/ )
    {
      if (GYa > 0)
      {
        while (GYa > 390 && GYa < 480)
        {
          col_ang();
          mot_ang(90);
        }
      }
      else if (GYa < 0)
      {
        while (GYa < -420 && GYa > -470)
        {
          col_ang();
          mot_ang(270);
        }
      }
      if (dis_back > 450)
      {
        mot_ang(180);
      }
      else if (dis_back < 300)
      {
        mot_ang(0);
      }
    }
    else STOP();
  }
  else STOP();
}
//------------move in width with VL53L0X------------
void MoveWidth_vl()
{
  reduction = 0.5;
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  if (Gy360 > 160 && Gy360 < 220)
  {
    if (Ba < 90 && Ba > 10) mot_ang(90);
    else if (Ba > 270 && Ba < 350) mot_ang(270);
    else STOP();
  }
  else Backtogoal();
}
/*
  void MoveWidth_vl()
  {
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);

  reduction = 0.5;
  if (abs(Cmp) <= 20)
  {
    if (dis_back > 250 && dis_back < 400)
    {
      if (DistanceB > 50)
      {
        if (Ba < 90 && Ba > 10 && DistanceGY < 80 )
        {
          digitalWrite(16, HIGH);
          digitalWrite(17, LOW);
          mot_ang(90);
        }
        else if (Ba > 270 && Ba < 350 && DistanceGY < 80 )
        {
          digitalWrite(17, HIGH);
          digitalWrite(16, LOW);
          mot_ang(270);
        }
        else {
          digitalWrite(16, LOW);
          digitalWrite(17, LOW);
          shift();
        }
      }
      else shift();
    }
    else if ((dis_back < 250 || dis_back > 500) )
    {
      Backtogoal();
    }
  }
  else STOP();
  }
*/
