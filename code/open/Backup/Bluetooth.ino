//  void serialEvent1()
//  { 
//    while ( Serial1.available() > 0)
//    {
//      char inChar = Serial1.read();
//  
//      if (inChar == '(') i = 0;
//  
//      if (i < 4 && i > 0)
//      {
//        BNOS += inChar;
//      }
//      if (inChar == '\n')
//      {
//        bno = BNOS.toInt();
//        BNOS = "";
//      }
//      i++;
//    }
//      bno = map(bno, 0, 360, 0, 1023);
//  if (bno - setcmp < 0) Cmp = 1023 - (setcmp - bno);
//  else  Cmp = bno - setcmp;
//  if (Cmp > 512) Cmp = Cmp - 1023;
//
//  }
//void serialEvent5()
//{
//  int i;
//  String OTBA;
//  String OTD;
//int hhhh;
//hhhh = Serial5.available();
//  while (hhhh > 0)
//  {
//    hhhh = Serial5.available();
//    char inChar = Serial5.read();
//    if (inChar == '(') i = 0;
//    if (i < 4 && i > 0)
//    {
//      OTBA += inChar;
//      //        Serial.println(OTBA);
//    }
//    else if (i > 3 && i < 7)
//    {
//      OTD += inChar;
//      //        Serial.println(OTD);
//    }
//    Serial.println(inChar);
//    if (inChar == '\n')
//    {
//      Other_Ba = OTBA.toInt();
//      Other_distance = OTD.toInt();
//      Serial.println(OTBA);
//      OTBA = "";
//      OTD = "";
//      //      Serial.println(Other_distance);
//    }
//    i++;
//  }
//}
// void Bluetooth()
// {
//
//  if (Other_distance>DistanceB)
//  {
//    analogWrite(Buzzer, HIGH);
//    sprintf(buff,"Distance khodesh  : %03d Distance other  : %03d KHODESH KAMTARE " , DistanceB,Other_distance);
//    Serial.println(buff);
//
//  }
//  else
//  {
//    sprintf(buff,"Distance khodesh  : %03d Distance other  : %03d OTHER KAMTARE " , DistanceB,Other_distance);
//    Serial.println(buff);
//    analogWrite(Buzzer, LOW);
//  }
// }
