//void serialEvent5() {
//  while (Serial5.available()) {
//    char inChar = (char)Serial5.read();
//    if (inChar == '(' )  {
//      joda = 0 ;
//    }
//    if (joda <= 3 && joda > 0)
//    {
//      Ang += inChar;
//    }
//    if (joda > 3 && joda < 7) {
//      dis += inChar;
//    }
//    if (joda == 7) {
//      ar += inChar;
//    }
//    if (inChar == '\n') {
//      stringComplete = true;
//      Angle = Ang.toInt();
//      Distancebl = dis.toInt();
//      Area = ar.toInt();
//      Ang = "";
//      dis = "";
//      ar = "";
//    }
//    joda++;
//  }
//}
//
//void BTReciever()
//{
//
//  if (DistanceB < Distancebl)
//  {
//    f = 1;
//  }
//  else
//  {
//    f = 0;
//  }
//  Serial5.println(f);
//  Serial.print(Distancebl);
//  Serial.print(" | ");
//  Serial.println(DistanceB);
//  Serial.print(sit);
//}
//void bluetL ()
//{
// if (stringComplete) {
//    //      Serial.println(Distance);
//    //    // clear the string:
//    //      dis = "";
//    //    stringComplete = false;
//    //  if (stringComplete) {
//    //    Serial.print(Distancebl);
//    //    Serial.print(" | ");
//    //    Serial.println(DistanceB);
//
//    stringComplete = false;
//    col_ang();
//    if (Ball)
//    {
//      if ( Ba >= 0 && Ba < 180 && Ang >= 0 && Ang < 180 )
//      {
//        if ( Ba <= Angle)
//        {
//          shift();
//          sit = '0';
//        }
//        else
//        {
//          STOP();
//          sit = '1';
//        }
//      }
//      else if ( Ba >= 180 && Ba < 360 && Angle >= 180 && Angle < 360 )
//      {
//        if ( Ba >= Angle )
//        {
//          shift();
//          sit = '0';
//        }
//        else
//        {
//          STOP();
//          sit = '1';
//        }
//      }
//      else if ( Ba >= 180 && Ba < 360 && Angle >= 0 && Angle < 180 )
//      {
//
//        if ((360 - Ba) <= Angle )
//        {
//          shift();
//          sit = '0';
//        }
//        else
//        {
//          STOP();
//          sit = '1';
//        }
//      }
//      else if ( Ba < 180 && Ba >= 0 && Angle >= 180 && Angle < 360 )
//      {
//        if ( (360 - Angle) >= Ba )
//        {
//          STOP();
//          sit = '1';
//        }
//      }
//    }
//    else {
//      STOP();
//      sit = '1';
//    } 
//}
//}
