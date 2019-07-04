void fout()
{
  int kaj;
  int bigball;
  int smallball;
  OC();
  col_ang();
  Bazi();
 
 kaj = Compass2;
  /////////// Right OUT////////////
  if (ra || rb)
  {
    mot_ang(270);
    ///////////
    if (kaj <= 20 && kaj > -90)
    {
      if (abs(kaj) <= 20)
      {
        bigball = 180;   smallball = 0;
      }
      else
      {
        bigball = 270;   smallball = 0;
      }
      while (Ba >= smallball && Ba <= bigball && Ball)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 20)
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
          if (fb)
          {
            while (!fa)
            {
              col_ang();
              OC();
              MOVE(210);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(320);
          if (bb)
          {
            while (!ba)
            {
              col_ang();
              OC();
              MOVE(320);
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
    else if (kaj > 20 && kaj <= 90)
    {
      smallball = 180;      bigball = 270;
      while ((Ba < smallball || Ba > bigball) && Ball)
      {
        OC();
        col_ang();
        //                if (abs(kaj) <= 20)
        //                {
        //                  bigball = 359;    smallball = 180;
        //                }
        if (fa || fb)
        {
          mot_ang(210);
          if (fb)
          {
            while (!fa)
            {
              col_ang();
              OC();
              MOVE(210);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(320);
          if (bb)
          {
            while (!ba)
            {
              col_ang();
              OC();
              MOVE(320);
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
  /////////end of right out
  else if (la || lb)
  {
    mot_ang(90);
    if (kaj >= -20 && kaj < 90)
    {
      if (abs (kaj) <= 20)
      {
        bigball = 360; smallball = 180;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 360; smallball = 90;
      }
      while (Ba > smallball && Ba < bigball && Ball)
      {
        OC();
        col_ang();
        if (abs (kaj) <= 20)
        {
          bigball = 360; smallball = 180;
        }
        else if (kaj > 20 && kaj < 90)
        {
          bigball = 360; smallball = 90;
        }
        if (fa || fb)
        {
          mot_ang(140);
          if (fb)
          {
            while (!fa)
            {
              OC();
              MOVE(140);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(50);
          if (bb)
          {
            while (!ba)
            { col_ang();
              OC();
              MOVE(50);
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
    else if (kaj < -20 && kaj > -90)
    {
      smallball = 90;    bigball = 180;
      while ((Ba < smallball || Ba > bigball) && Ball)
      {
        OC();
        col_ang();
        //        if (abs(kaj) <= 20)
        //        {
        //          bigball = 180;    smallball = 0;
        //        }
        if (fa || fb)
        {
          mot_ang(140);
          if (fb)
          {
            while (!fa)
            { col_ang();
              OC();
              MOVE(140);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(50);
          if (bb)
          {
            while (!ba)
            {
              col_ang();
              OC();
              MOVE(50);
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
    //if (Ba < smallball || Ba > bigball) shift();
  }
  ///////end of left out
  else if (fa || fb)
  {
    mot_ang(180);
    if (abs(kaj) <= 15)
    {
      bigball = 250;   smallball = 110;
    }
    else if (kaj > 20 && kaj < 90)
    {
      bigball = 180; smallball = 90;
    }
    else if (kaj < -20 && kaj > -90)
    {
      bigball = 270; smallball = 150;
    }
    while ((Ba < smallball) || (Ba > bigball) && Ball)
    {
      OC();
      col_ang();
      if (abs(kaj) <= 20)
      {
        bigball = 250;   smallball = 110;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 180; smallball = 90;
      }
      else if (kaj < -20 && kaj > -90)
      {
        bigball = 270; smallball = 150;
      }
      if (la || lb)
      {
        mot_ang(140);
        if (lb)
        {
          while (!la)
          {
            col_ang();
            OC();
            MOVE(140);
          }

        }
      }
      else if (ra || rb)
      {
        mot_ang(210);
        if (rb)
        {
          while (!ra)
          {
            col_ang();
            OC();
            MOVE(210);
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
  else if (ba || bb)
  {
    mot_ang(0);
    if (abs (kaj) <= 20)
    {
      bigball = 310; smallball = 50;
    }
    else if (kaj < -20 && kaj > -90)
    {
      bigball = 340;  smallball = 70;
    }
    else if (kaj > 20 && kaj < 90)
    {
      bigball = 310;  smallball = 40;
    }
    while ((Ba > smallball) && (Ba < bigball) && Ball)
    {
      OC();
      col_ang();
      if (abs (kaj) <= 20)
      {
        bigball = 310; smallball = 50;
      }
      else if (kaj < -20 && kaj > -90)
      {
        bigball = 340;  smallball = 70;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 310;  smallball = 40;
      }
      if (la || lb)
      {
        mot_ang(50);
        if (lb )
        {
          while (!la)
          { col_ang();
            OC();
            MOVE(50);
          }
        }
      }
      else if (ra || rb)
      {
        mot_ang(320);
        if (rb)
        {
          while (!ra)
          {
            col_ang();
            OC();
            MOVE(320);
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
