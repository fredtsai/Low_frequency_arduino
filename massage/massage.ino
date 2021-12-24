#include <MsTimer2.h>     //定時器庫的標頭檔案
#include <TimerOne.h>

int skin;
int inChar;   // OTG command
int po_out;  //輸出強度
int po_bat;  //暫存輸出
int po_low = 700; //最低輸出
int po_step = 1;  //輸出段數
int vol_out;  // 設定的強度
int state=0;
int run_=0;
int lose;
int cont=0;
int mode;
int key_memo = 0;
int key_scan = 0;
uint8_t p_up;
uint8_t p_down;
#define buzzer 7
#define in_1 3
#define in_2 2
#define sw_m 8
#define sw_p 12
#define det 13
#define power 10   //3fff
#define pad 14
byte mass[6] = {0xaa, 0x11, 0x00, 0x00, 0x02, 0xff}; //{0xaa, 0x11, 強度, 模式, 貼片, 0xff}
const long interval = 1000 ; //  1000 microseconds timer1 IRQ

//中斷服務程式
void TimerOne(){
  cont++;
}
//中斷服務程式2 MsTimer2
void onTimer(){
  get_vol();
  key_scan = true;
  int swp = digitalRead(sw_p);
  int swm = digitalRead(sw_m);
  if ((swm ==true)&&(swp ==true)){
    key_memo = false;
  }
  if ((key_memo == 0)&&(swp ==0)){
    delayMicroseconds(20);
    key_memo = true;
    p_up =true;
//    Serial.println("SW+ : on");
    voltage_comp();
  }
  
  if ((key_memo == 0)&&(swm ==0)){
    delayMicroseconds(20);
    key_memo = true;
    p_down =true;
//    Serial.println("SW- : on");
    if (run_ == false){
      state = true;
    }
    voltage_comp();
  }
  key_scan = false;
}
//接收APP data
void serialEvent() {
  while (Serial.available()) {
    // Read data from USB OTG
    inChar = Serial.read();   //(char)Serial.read(); 
    Serial.print(inChar);
    if (inChar == 0x70){
      state= 1;
      po_step=1;
      vol_out=po_low;
    }  
    else if (inChar == 0x71){
      state= 0;
      run_ = 0;
      po_step=1;
      vol_out=po_low;
    }
    else if (inChar == 0x62){
      p_up =1;
      BI(100);
      voltage_comp();
    }
    else if (inChar == 0x63){
      p_down =1;
      BI(100);
      voltage_comp();
    }
    else if (inChar == 0x81){
      run_ = 1;
      state = 1;
      voltage_comp();
    }
    else if (inChar == 0x82){
      run_ = 0;
      state = 0;
      voltage_comp();
    }
  }
}

void setup()
{
  Serial.begin(115200); //初始化串列埠
  pinMode(buzzer, OUTPUT);  //7
  pinMode(in_1, OUTPUT);  //3
  pinMode(in_2, OUTPUT);  //2
  pinMode(sw_p, INPUT_PULLUP);  //4
  pinMode(sw_m, INPUT_PULLUP);  //5
  pinMode(det, OUTPUT);  //13
  pinMode(pad, INPUT);  //14
  pinMode(power, OUTPUT);  //10
  
  analogReference(INTERNAL4V096);  // set analog reference to internal 4.096V
  MsTimer2::set(2, onTimer); //設定中斷，每2ms進入一次中斷服務程式 onTimer()
  MsTimer2::start(); //計時
  Timer1.initialize( interval ); // 初始化,  interval 以 micro sec 為單位
  Timer1.attachInterrupt( TimerOne ); // attach the service routine here  
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  digitalWrite(det, LOW);
  BI(200);
}

void loop(){
//  SKIN();
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);
  digitalWrite(det, LOW);
  vol_out=po_low; 
  analogWrite(power,2000);
  if (state ==1 ){
    SKIN();
    if (skin == 0){
      BI(100);
      delay(100);
    }
    else{
      run_=1;
    }
  }
  
  if ((state ==1 ) && (run_ == 1)){
    mass[2] = po_step; //
    mass[3] = mode; //
    mass[4] = 1; //
    Serial.write(mass, sizeof(mass));
    BI(100);
    AUTO();
  } 
}
//==============================================
