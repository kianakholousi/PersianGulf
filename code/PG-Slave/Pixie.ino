
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
        Bx = pcam.blocks[j].x - 156 + (pcam.blocks[j].height / 2);
        By = pcam.blocks[j].y - 94 + (pcam.blocks[j].width / 2);
        Ba = atan2(By , -Bx) * 180 / PI;
        if (Ba < 0) Ba = 360 + Ba;
        DistanceB = sqrt((Bx * Bx) + (By * By));
        DShift = 120 - DistanceB;
      }

      else if (pcam.blocks[j].signature == 2)////G Yellow
      {
        GYx = pcam.blocks[j].x - 150;
        GYx = -GYx;
        //        GYx = GYx - pcam.blocks[j].width / 2;
        if (GYx < 0) GYx = GYx - pcam.blocks[j].width / 2;
        else GYx = GYx + pcam.blocks[j].width / 2;
        GYy = pcam.blocks[j].y - 94 ;
        //        GYy = GYy - pcam.blocks[j].height / 2;
        if (GYy < 0) GYy = GYy - pcam.blocks[j].height / 2;
        else GYy = GYy + pcam.blocks[j].height  / 2;
        DistanceGY = sqrt((GYx * GYx) + (GYy * GYy)) - 40;
        GYa = atan2(GYy, GYx) * 1800 / PI;
        yell = GYa / 10;
        //        if (GYa < 0) GYa = 3600 + GYa;
        if (yell < 0) yell = 360 + yell;
        GYa = map(GYa, 0, 3600, 0, 1023);
        //        if (GYa > 512) GYa = GYa - 1024;
      }
      /* else if (pcam.blocks[j].signature == 2)////G Blue
        {
         GBx = pcam.blocks[j].x - 153;
         GBy = pcam.blocks[j].y - 98;
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
