//------------INTER_UP_T---------------------
void Counter()
{
  BC++;
  if (BC > 2) Ball = false;
  else Ball = true;
}
   //------------FRLB------------
void OS_Comparison()
{
  OS_Reader();
  if (OS[1]-OSP[1]>45) Fr1=1;
  else Fr1=0;
  if (OS[2]-OSP[2]>45) Fr2=1;
  else Fr2=0;
  if (OS[3]-OSP[3]>45) Ri1=1;
  else Ri1=0;
  if (OS[4]-OSP[4]>45) Ri2=1;
  else Ri2=0;
  if (OS[5]-OSP[5]>45) Le1=1;
  else Le1=0;
  if (OS[6]-OSP[6]>45) Le2=1;
  else Le2=0;
  if (OS[7]-OSP[7]>45) Ba1=1;
  else Ba1=0;
  if (OS[8]-OSP[8]>45) Ba2=1;
  else Ba2=0;
}
//------reading out sensors----
void OS_Reader()
{
  OS[1]=analogRead(Bit); //49
  OS[2]=analogRead(32);
  OS[3]=analogRead(23);
  OS[4]=analogRead(22);
  OS[5]=analogRead(18);
  OS[6]=analogRead(19);
  OS[7]=analogRead(16);
  OS[8]=analogRead(17); 
}
