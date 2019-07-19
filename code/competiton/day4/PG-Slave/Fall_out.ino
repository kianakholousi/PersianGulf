void fallout()
{
  int kaj;
  int bigball;
  int smallball;
  OC();
  col_ang();
  Bazi();

  kaj = yell;

  /////////// Right OUT////////////
  if (ra || rb)
  {
    mot_ang(270);
    ///////////
    if (kaj <= 20 && kaj > -90)
    {
      if (abs(kaj) <= 20)
      {
        bigball = 175;   smallball = 15;
      }
      else
      {
        bigball = 230;   smallball = 15;
      }
      while (Ba >= smallball && Ba <= bigball && Ball)
      {
        OC();
        col_ang();
        if (abs(kaj) <= 20)
        {
          bigball = 175;   smallball = 15;
        }
        else
        {
          bigball = 230;  smallball = 15;
        }

        if (fa || fb)
        {
          mot_ang(225);
          if (fb)
          {
            while (!fa)
            {
              col_ang();
              OC();
              MOVE(225);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(330);
          if (bb)
          {
            while (!ba)
            {
              col_ang();
              OC();
              MOVE(330);
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
    
      smallball = 150;      bigball = 315;
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
          mot_ang(200);
          if (fb)
          {
            while (!fa)
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
        bigball = 345; smallball = 165;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 280; smallball = 45;
      }
      while (Ba > smallball && Ba < bigball && Ball)
      {
        OC();
        col_ang();
        if (abs (kaj) <= 20)
        {
          bigball = 345; smallball = 165;
        }
        else if (kaj > 20 && kaj < 90)
        {
          bigball = 280; smallball = 45;
        }
        if (fa || fb)
        {
          mot_ang(120);
          if (fb)
          {
            while (!fa)
            {
              OC();
              MOVE(120);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(45);
          if (bb)
          {
            while (!ba)
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
    else if (kaj < -20 && kaj > -90)
    {
      smallball = 45;    bigball = 225
      ;
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
          mot_ang(150);
          if (fb)
          {
            while (!fa)
            { col_ang();
              OC();
              MOVE(150);
            }
          }
        }
        else if (ba || bb)
        {
          mot_ang(60);
          if (bb)
          {
            while (!ba)
            {
              col_ang();
              OC();
              MOVE(60);
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
      bigball = 315;   smallball = 45;
    }
    else if (kaj > 20 && kaj < 90)
    {
      bigball = 310; smallball = 120;
    }
    else if (kaj < -20 && kaj > -90)
    {
      bigball = 250; smallball = 50;
    }
    while ((Ba < smallball) || (Ba > bigball) && Ball)
    {
      OC();
      col_ang();
      if (abs(kaj) <= 20)
      {
        bigball = 315;   smallball = 45;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 310; smallball = 120;
      }
      else if (kaj < -20 && kaj > -90)
      {
        bigball = 250; smallball = 50;
      }
      if (la || lb)
      {
        mot_ang(120);
        if (lb)
        {
          while (!la)
          {
            col_ang();
            OC();
            MOVE(120);
          }

        }
      }
      else if (ra || rb)
      {
        mot_ang(225);
        if (rb)
        {
          while (!ra)
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
  else if (ba || bb)
  {
    mot_ang(0);
    if (abs (kaj) <= 20)
    {
      bigball = 220; smallball = 160;
    }
    else if (kaj < -20 && kaj > -90)
    {
      bigball = 260;  smallball = 100;
    }
    else if (kaj > 20 && kaj < 90)
    {
      bigball = 260;  smallball = 100;
    }
    while ((Ba > smallball) && (Ba < bigball) && Ball)
    {
      OC();
      col_ang();
      if (abs (kaj) <= 20)
      {
        bigball = 220;  smallball = 160;
      }
      else if (kaj < -20 && kaj > -90)
      {
        bigball = 260;  smallball = 100;
      }
      else if (kaj > 20 && kaj < 90)
      {
        bigball = 260;  smallball = 100;
      }
      if (la || lb)
      {
        mot_ang(45);
        if (lb )
        {
          while (!la)
          { col_ang();
            OC();
            MOVE(45);
          }
        }
      }
      else if (ra || rb)
      {
        mot_ang(330);
        if (rb)
        {
          while (!ra)
          {
            col_ang();
            OC();
            MOVE(330);
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
