void fallout()
{
  int kaj;
  int bigball;
  int smallball;
  OC();
  col_ang();
  if (flag == 0)
  {
    kaj = Cmp;
  }
  if (flag == 1) {
    kaj = yell;
  }
  /////////// Right OUT////////////
  if (ra == 1 || rb == 1)
  {
    mot_ang(270);
    /////////
    if (kaj <= 10 && kaj > -350)
    {
      if (abs(kaj) <= 10)
      {
        bigball = 180;   smallball = 0;
      }
      else
      {
        bigball = 270;  smallball = 0;
      }
      while (Ba >= smallball && Ba <= bigball && i < 5)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 10)
        {
          bigball = 180;   smallball = 0;
        }
        else
        {
          bigball = 270;  smallball = 0;
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
              mot_ang(200);
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
              mot_ang(315);
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
    else if (kaj > 10 && kaj <= 350)
    {
      smallball = 180;      bigball = 270;
      while ((Ba < smallball || Ba > bigball) && i < 5)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 10)
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
              mot_ang(200);
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
              mot_ang(315);
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
    if (kaj >= -10 && kaj < 350)
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
              mot_ang(135);
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
              mot_ang(45);
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
    else if (kaj < -10 && kaj > -350)
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
              mot_ang(135);
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
              mot_ang(45);
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
            mot_ang(135);
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
            mot_ang(225);
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
            mot_ang(45);
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
            mot_ang(300);
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
