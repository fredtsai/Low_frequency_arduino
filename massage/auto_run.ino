void AUTO(){
  MsTimer2::start(); //開始計時
  uint8_t i,j;
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  digitalWrite(det, LOW);
//  Serial.println ("AUTO_RUN");
  delay(5000);
  BI(100);
//  Serial.println ("AUTO_start");
  i=15;
  while(i--&& run_){
    mass500();
    }
  
  i=12;
  while(i--&& run_){
    mass250();
    }
  
  i=12;
  while(i--&& run_){
    mass120();
    }
  
  i=12;
  while(i--&& run_){
    mass60();
    delay(300);
    }
  
  i=6;
  while(i--&& run_){
    mass500();
    }
  
  int Loop=3;                     //
  while(Loop--&& run_){        
      i=3;
      while(i--&& run_){
        po_out=po_low;
        delay(300);
        mass50();
        po_bat=vol_out;
        delay(500);
        
        vol_out=po_bat;
        mass50();
        po_bat=vol_out;
        delay(500);
          
        vol_out=po_bat;
        mass50();
        delay(300);
        }

      i=20;
      while(i--&& run_){         //
        mass250();
        mass50();
        }
      
      i=5; 
      while(i--&& run_){         //
        mass500();
        mass500();
        mass500();
        mass50();
        }
      
      i=20;
      while(i--&& run_){         //
        mass250();
        mass50();
        }
      
      i=6;
      while(i--&& run_){         //
        mass500();
        mass500();
        mass500();
        mass50();
        }
  }    

  i=2;
  while(i--&& run_){
      vol_out=po_low;
      delay(300);
      mass60();
      po_bat=vol_out;
      delay(500);
      
      vol_out=po_bat;
      mass60();
      po_bat=vol_out;
      delay(500);    
        
      vol_out=po_bat;
      mass60();
      delay(300);
      }
  i=10;
  while(i--&& run_){
    mass120();
    }
  
  i=10;
  while(i--&& run_){
    mass250();
    }
  
  i=10;
  while(i--&& run_){
    if(po_out>po_low){
      po_out=po_out-5;
      }
    mass500();
  }
  Power_down();  
}
