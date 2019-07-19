///////////////////////////////////////////////////
void chop() {
  OC();
  //  Serial.print("FO=");
  //  Serial.print(FO);
  //  Serial.print(" | ");
  //  Serial.print("FI=");
  //  Serial.print(FI);
  //  Serial.print(" | ");
  //  Serial.print("RO=");
  //  Serial.print(RO);
  //  Serial.print(" | ");
  //  Serial.print("RI=");
  //  Serial.print(RI);
  //  Serial.print(" | ");
  //  Serial.print("LO=");
  //  Serial.print(LO);
  //  Serial.print(" | ");
  //  Serial.print("LI=");
  //  Serial.print(LI);
  //  Serial.print(" | ");
  //  Serial.print("BO=");
  //  Serial.print(BO);
  //  Serial.print(" | ");
  //  Serial.print("BI=");
  //  Serial.println(BI);
  //  Serial.print("fa=");
  //  Serial.print(fa);
  //  Serial.print(" | ");
  //  Serial.print("fb=");
  //  Serial.print(fb);
  //  Serial.print(" | ");
  //  Serial.print("ra=");
  //  Serial.print(ra);
  //  Serial.print(" | ");
  //  Serial.print("rb=");
  //  Serial.print(rb);
  //  Serial.print(" | ");
  //  Serial.print("la=");
  //  Serial.print(la);
  //  Serial.print(" | ");
  //  Serial.print("lb=");
  //  Serial.print(lb);
  //  Serial.print(" | ");
  //  Serial.print("ba=");
  //  Serial.print(ba);
  //  Serial.print(" | ");
  //  Serial.print("bb=");
  //  Serial.println(bb);

  //  Serial.print("Ba= ");
  //  Serial.print(Ba);
  //  Serial.print(" ** ");
  //  Serial.print("BayCenter= ");
  //  Serial.print(BayCenter);
  //  Serial.print(" ** ");
  //  Serial.print("BAxcenter= ");
  //  Serial.print(BAxcenter);
  //  Serial.print("  **   ");
  //  Serial.print("BxCenter= ");
  //  Serial.print(BxCenter);
  //  Serial.print(" ** ");
  //  Serial.print("ByCenter= ");
  //  Serial.print(ByCenter);
  //  Serial.println(" ** ");
  //  Serial.print(GYxCenter);
  //  Serial.print("||");
  //  Serial.print(GYyCenter);
  //  Serial.print("||");
  //  Serial.print(GYx);
  //  Serial.print("||");
  //  Serial.println(GYa);
  //  Serial.print(BxCenter);
  //  Serial.print(" | ");
  //  Serial.print(ByCenter);
  //  Serial.print(" | ");
  //  Serial.print(BxCenter - 40);
  //  Serial.print(" | ");
  //  Serial.print(Ba);
  //  Serial.print(" | ");
  //    Serial.println(Gy360);
  //--------------------cmps03
  //  Serial.print(Compass2);
  //  Serial.print("|");
  //  Serial.print(Compass);
  //  Serial.print("|");
  //      Serial.println(Cmp);

  Serial.print(Bx);
  Serial.print(" | ");
  Serial.print(By);
  Serial.print(" | ");
  Serial.println(Ba);
  Serial.print(arz);
  Serial.print("|");
  Serial.print(DistanceB);
  Serial.print("|");
  Serial.println(Ba);

  delay(50);

}
//------------goaldon
//  if (!(Ball) || DistanceB > 90 || dis_back > 500 )
//  {
//    Backtogoal();
//  }
//  else if (dis_back < 300)
//  {
//    mot_ang(0);
//  }
//  else if ((Ba < 270 && Ba > 90) || (DistanceB < 85 && dis_back < 650)) fallout();
//   if (Ball && DistanceB < 120 )
//      {
//        MoveWidth_vl();
//      }
