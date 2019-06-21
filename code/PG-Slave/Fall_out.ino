void fallout()
{
  int kaj;
  int bigball;
  int smallball;
  OC();
  col_ang();
  Bazi();
  if (!flag)
  {
    kaj = Compass2;
  }
  if (flag) {
    kaj = yell;
  }
  /////////// Right OUT////////////
  if (ra || rb)
  {
    mot_ang(270);
    ///////////
    if (kaj <= 15 && kaj > -90)
    {
      if (abs(kaj) <= 15)
      {
        bigball = 210;   smallball = 15;
      }
      else
      {
        bigball = 315;   smallball = 45;
      }
      while (Ba >= smallball && Ba <= bigball && Ball)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 15)
        {
          bigball = 225;   smallball = 15;
        }
        else
        {
          bigball = 315;  smallball = 45;
        }

        if (fa || fb)
        {
          mot_ang(210);
          if (fb == 1)
          {
            while (fa == 0)
            {
              col_ang();
              OC();
              MOVE(200);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(320);
          if (bb == 1 )
          {
            while (ba == 0)
            {
              col_ang();
              OC();
              MOVE(315);
            }
          }
        }
        else if (rb)
        {
          while (!ra)
          {
            col_ang();
            OC();
            mot_ang(270);
          }
        }
        else if (ra)
          mot_ang(270);
        else
          STOP();
      }
    }
    ////////oonvar kaj/////////
    else if (kaj > 15 && kaj <= 135)
    {
      smallball = 225;      bigball = 315;
      while ((Ba < smallball || Ba > bigball) && i < 5)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 15)
        {
          bigball = 359;    smallball = 180;
        }
        if (fa || fb)
        {
          mot_ang(210);
          if (fb == 1)
          {
            while (fa == 0)
            {
              col_ang();
              OC();
              MOVE(200);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(320);
          if (bb == 1 )
          {
            while (ba == 0)
            {
              col_ang();
              OC();
              MOVE(315);
            }
          }
        }
        else if (rb)
        {
          while (!ra)
          { col_ang();
            OC();
            mot_ang(270);
          }
        }
        else if (ra)
          mot_ang(270);
        else
          STOP();
      }
    }
  }
  ///////////end of right out
  else if (la == 1 || lb == 1)
  {
    mot_ang(90);
    if (kaj >= -10 && kaj < 90)
    {
      if (abs (kaj) <= 10)
      {
        bigball = 360; smallball = 180;
      }
      else if (kaj > 10 && kaj < 350)
      {
        bigball = 360; smallball = 90;
      }
      while (Ba > smallball && Ba < bigball && i < 5)
      {
        OC();
        col_ang();
        if (abs (kaj) <= 10)
        {
          bigball = 360; smallball = 180;
        }
        else if (kaj > 10 && kaj < 350)
        {
          bigball = 360; smallball = 90;
        }
        if (fa || fb)
        {
          mot_ang(140);
          if (fb == 1)
          {
            while (fa == 0)
            {
              OC();
              MOVE(135);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(50);
          if (bb == 1 )
          {
            while (ba == 0)
            { col_ang();
              OC();
              MOVE(45);
            }
          }
        }
        else if (lb)
        {
          while (!la)
          { col_ang();
            OC();
            mot_ang(90);
          }
          mot_ang(90);
        }
        else if (la)
          mot_ang(90);
        else
          STOP();
      }
    }
    else if (kaj < -10 && kaj > -90)
    {
      smallball = 90;    bigball = 180;
      while ((Ba < smallball || Ba > bigball) && i < 5)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 10)
        {
          bigball = 180;    smallball = 0;
        }
        if (fa || fb)
        {
          mot_ang(140);
          if (fb == 1)
          {
            while (fa == 0)
            { col_ang();
              OC();
              MOVE(135);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(50);
          if (bb == 1 )
          {
            while (ba == 0)
            {
              col_ang();
              OC();
              MOVE(45);
            }
          }
        }
        else if (lb)
        {
          while (!la)
          {
            col_ang();
            OC();
            mot_ang(90);
          }
          mot_ang(90);
        }
        else if (la)
          mot_ang(90);
        else
          STOP();
      }
    }
    if (Ba < smallball || Ba > bigball) shift();
  }
  /////////end of left out
  else if (fa == 1 || fb == 1)
  {
    mot_ang(180);
    if (abs(kaj) <= 10)
    {
      bigball = 250;   smallball = 110;
    }
    else if (kaj > 10 && kaj < 350)
    {
      bigball = 180; smallball = 90;
    }
    else if (kaj < -10 && kaj > -350)
    {
      bigball = 270; smallball = 150;
    }
    while ((Ba < smallball) || (Ba > bigball) && i < 5)
    {
      OC();
      col_ang();
      if (la || lb)
      {
        mot_ang(140);
        if (lb == 1 )
        {
          while (la == 0)
          {
            col_ang();
            OC();
            MOVE(135);
          }
        }
      }
      else if (ra || rb)
      {
        mot_ang(210);
        if (rb == 1 )
        {
          while (ra == 0)
          {
            col_ang();
            OC();
            MOVE(225);
          }
        }
      }
      else if (fb)
      {
        while (!fa)
        {
          col_ang();
          OC();
          mot_ang(180);
        }
        mot_ang(180);
      }
      else if (fa)
        mot_ang(180);
      else
        STOP();
    }
  }
  else if (ba == 1 || bb == 1)
  {
    mot_ang(0);
    if (abs (kaj) <= 10)
    {
      bigball = 310;  smallball = 50;
    }
    else if (kaj < -10 && kaj > -64)
    {
      bigball = 340;  smallball = 70;
    }
    else if (kaj > 10 && kaj < 64)
    {
      bigball = 310;  smallball = 40;
    }
    while ((Ba > smallball) && (Ba < bigball) && i < 5)
    {
      OC();
      col_ang();
      if (la || lb)
      {
        mot_ang(50);
        if (lb == 1 )
        {
          while (la == 0)
          { col_ang();
            OC();
            MOVE(45);
          }
        }
      }
      else if (ra || rb)
      {
        mot_ang(320);
        if (rb == 1 )
        {
          while (ra == 0)
          {
            col_ang();
            OC();
            MOVE(300);
          }
        }
      }
      else if (bb)
      {
        while (!ba)
        {
          col_ang();
          OC();
          mot_ang(0);
        }
      }
      else if (ba)
        mot_ang(0);
      else
        STOP();
    }
  }
  else {
    shift();
  }
}
