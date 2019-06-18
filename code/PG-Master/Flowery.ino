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
///////////////////////////back to goal kiana////////////////////////
void backtogoal() {
  VL_Reader();
  if (dis_back > 1000)
  {
    mot_ang(180);
  }
  else if (dis_back < 200)
  {
    mot_ang(0);
  }
  else
    STOP();
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
void Backtogoal_d()
{
  reduction = 0.5;
  if (abs(Cmp) <= 50)
  {
    if (dis_back > 25 && dis_back < 40 && (GYa < 15 || GYa > 345)   ) STOP();
    else if ((dis_back < 25 || dis_back > 40) || (GYa > 15 && GYa < 345) )
    {

      if (GYa > 15 && GYa < 180)
      {
        mot_ang(90);
      }
      else if (GYa < 345 && GYa > 180)
      {
        mot_ang(270);
      }
      if (dis_back > 40)
      {
        mot_ang(180);
      }
      else if (dis_back < 25)
      {
        mot_ang(0);
      }
    }
    else STOP();
  }
  else STOP();
}
//------------move in width with VL53L0X------------
void MoveWidth_d()
{
  reduction = 0.5;
  if (abs(Cmp) <= 50)
  {
    if (dis_back > 25 && dis_back < 40 && (GYa > 350 || GYa < 15 ))
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
    else if ((dis_back < 25 || dis_back > 40) && (GYa > 25 || GYa < 355) )
    {
      Backtogoal_d();
    }
  }
  else STOP();
}
