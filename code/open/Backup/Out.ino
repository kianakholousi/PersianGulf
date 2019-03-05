//------------FRLB------------
void OS_Comparison()
{
  OS_Reader();
  if (OS[1]-OSP[1]>60) Fr1=1;
  else Fr1=0;
  if (OS[2]-OSP[2]>60) Fr2=1;
  else Fr2=0;
  if (OS[3]-OSP[3]>60) Ri1=1;
  else Ri1=0;
  if (OS[4]-OSP[4]>60) Ri2=1;
  else Ri2=0;
  if (OS[5]-OSP[5]>60) Le1=1;
  else Le1=0;
  if (OS[6]-OSP[6]>60) Le2=1;
  else Le2=0;
  if (OS[7]-OSP[7]>60) Ba1=1;
  else Ba1=0;
  if (OS[8]-OSP[8]>60) Ba2=1;
  else Ba2=0;
}
//------reading out sensors----
void OS_Reader()
{
  OS[1]=analogRead(31); //49
  OS[2]=analogRead(32);
  OS[3]=analogRead(23);
  OS[4]=analogRead(22);
  OS[5]=analogRead(18);
  OS[6]=analogRead(19);
  OS[7]=analogRead(16);
  OS[8]=analogRead(17); 
}
