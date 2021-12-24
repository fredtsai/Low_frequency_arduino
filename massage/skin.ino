
void BI(int n){
  for( int i=0 ; i<=n ; i++){
    digitalWrite(buzzer,HIGH);
    delayMicroseconds(250);
    digitalWrite(buzzer,LOW);
    delayMicroseconds(250);
  }
}
void SKIN(){
  if ( key_scan == 0){
    digitalWrite(det, LOW);
    delayMicroseconds(100);
    digitalWrite(in_1, HIGH);
    delayMicroseconds(200);
    int n = digitalRead(pad);
    digitalWrite(in_1, LOW);
    if ( n == false){ 
      BI(200);
      delay(2000);
      BI(200);
      skin = false;
      mass[4] = 0; //
      Serial.write(mass, sizeof(mass));
//      Serial.println ("Skin_err");
    }
    else {
      skin = true;
      delay(10);
//      Serial.println ("Skin_ok");
      digitalWrite(det, HIGH);
    }
//  return skin;
  }
  
}
