int LBa = 0, RBa = 0;
//------------backtogoal with yellow------------
void Backtogoal()
{
  VL_Reader();
  reduction = 0.6;
  if (DistanceGY > 30 && DistanceGY < 45 && GYa > 145 && GYa < 210 ) STOP();
  else if ((DistanceGY < 30 || DistanceGY > 45) || (GYa > 220 || GYa < 135) )
  {
    if (DistanceGY < 30)
    {
      mot_ang(180);
    }
    else if (DistanceGY > 45)
    {
      mot_ang(0);
    }
    if (GYa < 145)
    {
      mot_ang(90);
    }
    else if (GYa > 210)
    {
      mot_ang(270);
    }
  }
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
   digitalWrite(15, HIGH);
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
  digitalWrite(14, HIGH);
  reduction = 0.5;
  if (abs(Cmp) <= 20)
  {
    if (dis_back > 250 && dis_back < 400 /*&& (GYa > 350 || GYa < 15 )*/)
    {
      if (DistanceB > 100)
      {
        if (Ba < 90 && Ba > 10 && DistanceGY < 80 )
        {
          while (Ba < 90 && Ba > 10 && DistanceGY < 80)
          {
            col_ang();
            mot_ang(90);
          }
        }
        else if (Ba > 270 && Ba < 350 && DistanceGY < 80 )
        {
          while (Ba > 270 && Ba < 350 && DistanceGY < 80)
          {
            col_ang();
            mot_ang(270);
          }
        }
      }
      else shift();
    }
    else if ((dis_back < 250 || dis_back > 500) /*&& (GYa > 25 || GYa < 355)*/ )
    {
      Backtogoal_vl();
    }
  }
  else STOP();
}
