
int pin_arr[]           = {2,4,5,18,19,21,22,23};
int button_state_arr[]  = {0,0};
int i=0;
bool isrewind = false;
bool flag = false;

void setup() {
  Serial.begin(115200);
  for (int i; i<8; i++){
    pinMode(pin_arr[i], OUTPUT);
  }
  pinMode(15, INPUT);

}

void loop() {
  button_state_arr[1] = digitalRead(15);
  if ((button_state_arr[0]==0) && (button_state_arr[1]==1)){
    flag=true;
  }

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
    button_state_arr[0] = button_state_arr[1];
    flag=false;
    break;
  } 
  
  button_state_arr[0] = button_state_arr[1];
  digitalWrite(pin_arr[i], HIGH);
  Serial.println("===============================================");
}
