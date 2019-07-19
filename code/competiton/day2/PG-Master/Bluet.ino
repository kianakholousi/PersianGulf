void serialEvent5() {
  while (Serial5.available()) {
    char inChar = (char)Serial5.read();
    if (inChar == '(' )  {
      joda = 0 ;
    }
    {
      Ang += inChar;
    }
    if (joda > 3 && joda < 7) {
      dis += inChar;
    }
    if (inChar == '\n') {
      stringComplete = true;
      Angle = Ang.toInt();
      Distancebl = dis.toInt();
      Ang = "";
      dis = "";
    }
    joda++;
  }
}

void BTReceiver()
{
  if (DistanceB < 100) DisB = true;
  else DisB = false;
  if (Distancebl < 100) Disbl = true;
  else Disbl = false;
}


void bluetL ()
{
  if (stringComplete) {
    //      Serial.println(Distance);
    //    // clear the string:
    //      dis = "";
    //    stringComplete = false;
    //  if (stringComplete) {
    //    Serial.print(Distancebl);
    //    Serial.print(" | ");
    //    Serial.println(DistanceB);

    stringComplete = false;
    col_ang();
    if (Ball)
    {
      if (DisB) {
        fallout();
        sit = '0';
      }
      else if (!Disbl && !DisB) {
        if ( Ba >= 0 && Ba < 180 && Ang >= 0 && Ang < 180 )
        {
          if ( Ba <= Angle)
          {
            fallout();
            sit = '0';
          }
          else
          {
            STOP();
            sit = '1';
          }
        }
        else if ( Ba >= 180 && Ba < 360 && Angle >= 180 && Angle < 360 )
        {
          if ( Ba >= Angle )
          {
            fallout();
            sit = '0';
          }
          else
          {
            STOP();
            sit = '1';
          }
        }
        else if ( Ba >= 180 && Ba < 360 && Angle >= 0 && Angle < 180 )
        {

          if ((360 - Ba) <= Angle )
          {
            fallout();
            sit = '0';
          }
          else
          {
            STOP();
            sit = '1';
          }
        }
        else if ( Ba < 180 && Ba >= 0 && Angle >= 180 && Angle < 360 )
        {
          if ( (360 - Angle) >= Ba )
          {
            STOP();
            sit = '1';
          }
        }
      }
      else
      { sit = '1';
        //    Backtogoal();
        while ((DistanceGY < 30 || DistanceGY > 45) || (GYa > 220 || GYa < 135)) {
          mot_ang(180);
        }
      }

    }
  }
}
