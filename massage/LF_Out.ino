void massage(int n){
//  Serial.println(n);
  pulse_out();
  cont=0;
  mass[2] = po_step; //
  mass[3] = mode; //
  mass[4] = 1; //
  Serial.write(mass, sizeof(mass));
  while (Serial.available()) {
    // Read data from USB OTG
    inChar = Serial.read();   //(char)Serial.read(); 
    Serial.print(inChar);
    if (inChar == 0x71){
      state= 0;
      run_ = 0;
      po_step=1;
      vol_out=po_low;
    }
    else if (inChar == 0x62){
      p_up =1;
//      BI(100);
      voltage_comp();
    }
    else if (inChar == 0x63){
      p_down =1;
//      BI(100);
      voltage_comp();
    }
  } 
  while (cont <= n){
    SKIN();
    if(skin == false){
      po_step=1;
      vol_out=po_low;
      }
    }  
}

void mass500() {
//  Serial.println("mas_500");
  mode=1;
  uint8_t i;
  for (i=0;i<=3;i++) {
    massage(500);
  }
}

void mass250() {
  mode=1;
//  Serial.println("mas_250");
  uint8_t i;
  for (i=0;i<=8;i++) {
    massage(250);
  }
}

void mass120() {
  mode=2;
  Serial.println("mas_120");
  uint8_t i,j;
  for(i=0;i<17;i++){
    massage(120);
  }
}

void mass60() {
  mode=3;
  Serial.println("mas_60");
  uint8_t i;
  for (i=0;i<=35;i++) {
    massage(60);
  }
}

void mass50() {
  Serial.println("mas_50");
  mode=3;
  uint8_t i;
  for (i=0;i<=60;i++) {
    massage(50);  
  }
}
void pulse_out(){
//  SKIN();
  if(run_==1){   //(skin==1) && (run_==1)
    for (int i=0;i<=2;i++){
      digitalWrite(in_1, HIGH);
      delayMicroseconds(900);
      digitalWrite(in_1, LOW);
      digitalWrite(in_2, HIGH);
      delayMicroseconds(900);
      digitalWrite(in_2, LOW);
    }   
//      digitalWrite(in_1, HIGH);
//      delayMicroseconds(100);
//      digitalWrite(in_1, LOW);
  }  
}
