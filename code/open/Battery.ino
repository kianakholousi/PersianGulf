void Battery(void)
 {
  float V;
   V = ((16.8*(float)(analogRead(20))/780));
//   Serial.println(V);
   if (V<=16.8 && V>16)
   {
   digitalWrite(24,HIGH);
   digitalWrite(25,HIGH);
   digitalWrite(26,HIGH);
   digitalWrite(27,HIGH);
   digitalWrite(Buzzer,LOW);
   }
   else if (V<=16 && V>15)
   {
   digitalWrite(24,HIGH);
   digitalWrite(25,HIGH);
   digitalWrite(26,HIGH);
   digitalWrite(27,LOW);
   digitalWrite(Buzzer,LOW);
   }
   else if (V<=15 && V>14)
   {
   digitalWrite(24,HIGH);
   digitalWrite(25,HIGH);
   digitalWrite(26,LOW);
   digitalWrite(27,LOW);
   digitalWrite(Buzzer,LOW);
   }
     else if (V<14)
   {  
   digitalWrite(24,HIGH);
   digitalWrite(25,LOW);
   digitalWrite(26,LOW);
   digitalWrite(27,LOW);
   digitalWrite(Buzzer,HIGH);
   }

// //  reduction = (25.2-V)*0.8/12.6;
//     reduction = 11 / V;  
//     if(reduction > 1) reduction = 1;
   }
