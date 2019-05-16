
//------------spin speed------------
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  compass_input = Cmp ;
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value * 1.5);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;
//  if ( compass_input >= zero_degree )
//    compass_output = (compass_input / divided_value) + added_value;
//  else if (compass_input <= (-zero_degree) )
//    compass_output = -((-compass_input) / divided_value) - added_value;
//  else
//    compass_output = 0;
//  return compass_output;
}

//------------spin yellow------------
signed int spin_yellow (int added_value)
{
  
////  int input = 0, output = 0;
////  input = GYa ;
////  if (GYa < 5 || GYa > 355) output = 0;
////  else if (GYa > 180)
////  {
////    output = 4 * (GYa - 360) - added_value;
////  }
////  else if (GYa <= 180)
////  {
////    output = 4 * GYa + added_value;
////  }
////return -output;
//  int input = 0, output = 0;
//  input = GYa ;
//  if ( input > 180 && input < 350 )
//    output = (input) + added_value;
//  else if (input <= 180 && input > 10 )
//    output = -((input) ) - added_value - 180;
//  else
//    output = 0;
//  return output/2;
//  
}
