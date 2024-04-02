#include <ESP32.h>

int pin_arr[]           = {2,4,5,18,19,21,22,23};
int button_state_arr[]  = {0,0};
int i=0;
bool isrewind = false;
bool flag = false;

hw_timer_t *My_timer = NULL;


void IRAM_ATTR onTimer(){
  flag = true;
}


void setup() {
  Serial.begin(115200);
  for (int i; i<8; i++){
    pinMode(pin_arr[i], OUTPUT);
  }

  // Timer Interrupt  
  My_timer = timerBegin(0, 80, true);               // timerBegin([which timer], prescaler, count up(true)/down)
  timerAttachInterrupt(My_timer, &onTimer, true);   // attaching function that will serve as interrupt
  timerAlarmWrite(My_timer, 250000, true);         // 1000000 (micros), true (for reload so it generated periodically)
  timerAlarmEnable(My_timer);                       // Just Enable
}


void loop() {
  while(flag==true){  
    if (isrewind){
      i--;
      digitalWrite(pin_arr[i+1], LOW);
      if (i==0){
        isrewind = false;
      }
    } else{
      i++;
      digitalWrite(pin_arr[i-1], LOW);
      if (i==7){
        isrewind = true;
      }
    }
    flag=false;
    break;
  } 
  
  digitalWrite(pin_arr[i], HIGH);
  // Serial.println("===============================================");
}
