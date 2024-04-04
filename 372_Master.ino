#define PUSH_BUTTON 3
int state_0;
int state_1;
int value;

void setup() {
    Serial.begin(9600);
}

void button_pushed(){
    state_1 = digitalRead(PUSH_BUTTON);
    if (state_0 == 0 && state_1 == 1){
        value = 1;
    } else{
        value = 0;
    }
    state_0 = state_1
}

void loop() {
    Serial.write(value);
    delay(1000);
}