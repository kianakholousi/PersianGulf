
//------------color to angle------------
void col_ang()
{
  uint16_t blocks;
  int j;
  blocks = pcam.getBlocks();
  if (blocks)
  {
    for (int j = 0; j < blocks; j++)
    {
      if (pcam.blocks[j].signature == 1)
      {
        BC = 0;
        Bx = pcam.blocks[j].x - 160 + (pcam.blocks[j].width / 2);
        By = pcam.blocks[j].y - 90 + (pcam.blocks[j].height / 2);
        DistanceB = sqrt((Bx * Bx) + (By * By)) ;
        DShift = 120 - DistanceB;
        Ba = atan2(By, Bx) * 180 / PI;
        if (Ba < 0) Ba = 360 + Ba;
      }

      else if (pcam.blocks[j].signature == 3)////G Yellow
      {
        GYx = abs (pcam.blocks[j].x - 151) + (pcam.blocks[j].width / 2);
        GYy = abs (pcam.blocks[j].y - 102) + (pcam.blocks[j].height / 2);
        GYx = -GYx;
        DistanceGY = sqrt((GYx * GYx) + (GYy * GYy)) - 40;
        GYa = atan2(GYy, GYx) * 1800 / PI;
        GYa = atan2(GYy, -GYx) * 1800 / PI;
        yell = GYa / 10;
        if (yell < 0) yell = 360 + yell;
        if (GYa < 0) GYa = 3600 + GYa;
        GYa = map(GYa, 0, 3600, 0, 1023);
        if (GYa > 512) GYa = GYa - 1023;
        if (GYa < 0) GYa = GYa + 3600;
      }
      /* else if (pcam.blocks[j].signature == 2)////G Blue
        {
         GBx = pcam.blocks[j].x - 160;
         GBy = pcam.blocks[j].y - 97;
         GBxCenter = abs (GBx) + (pcam.blocks[j].width / 2);
         GByCenter = abs (GBy) + (pcam.blocks[j].height / 2);
         GBx = -GBx;
         DistanceGB = pcam.blocks[j].width;
         GBa = atan2(GBy, GBx) * 180 / PI;
         if (GBa < 0) GBa = GBa + 360;
        } */

    }
  }
}
