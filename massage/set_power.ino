void Power_down(){
  run_ = 0;
  state = 0;
  power_out(po_low);
  mass[2] = 1; //
  mass[3] = 4; //
  mass[4] = 1; //
  Serial.write(mass, sizeof(mass));
  BI(500); 
}

void power_out(int n){
  analogWrite(power,n); 
}

void get_vol(){
    if(po_out < vol_out){
      po_out++;
    }
    else{
      po_out--;
    }
    analogWrite(power,po_out); 
}

void voltage_comp() { 
  uint8_t n;
  BI(200);
  if ((p_up==true)&&(run_==true)){
   p_up=false;
   if(po_step < 15){
     po_step++;
//     Serial.print("po_step +: ");
//     Serial.println(po_step);
//     BI(100);
//     vol_out=po_low;
   }
   else {
//      Serial.print("over +");
      BI(100);
      delay(500);
      BI(100);
        }
  }
    if ((p_down==true)&&(run_==true)){
      p_down=false;
      if(po_step > 1){
        po_step--;
//        Serial.print("po_step -: ");
//        Serial.println(po_step);
//        BI(100);
      }
      else {
//        Serial.print("over -");
        BI(100);
        delay(500);
        BI(100);
     }
   }
   
   switch (po_step){ 
     case 1:
       vol_out=po_low;
//       Serial.print("vol_out= ");
//       Serial.println(vol_out);
       break;
     case 2:
       vol_out=po_low+400;
//       Serial.print("vol_out= ");
//       Serial.println(vol_out);
       break;
     case 3:
       vol_out=po_low+600;
//       Serial.print("vol_out= ");
//       Serial.println(vol_out);
       break;
     case 4:
       vol_out=po_low+800;
//       Serial.print("vol_out= ");
//       Serial.println(vol_out);
       break;
     case 5:
       vol_out=po_low+1000;
//       Serial.print("vol_out= ");
//       Serial.println(vol_out);
       break;
     case 6:
       vol_out=po_low+1200;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 7:
       vol_out=po_low+1500;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 8:
       vol_out=po_low+2000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 9:
       vol_out=po_low+2500;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 10:
       vol_out=po_low+3000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 11:
       vol_out=po_low+4000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 12:
       vol_out=po_low+5000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 13:
       vol_out=po_low+7000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 14:
       vol_out=po_low+11000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;
     case 15: 
       vol_out=po_low+15000;
       Serial.print("vol_out= ");
       Serial.println(vol_out);
       break;          
   }
//   SKIN();    
//    if(skin==false){
//   po_step=1;
//    run_=false;
//   }
}
