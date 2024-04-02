#include <ESP32.h>

int pin_arr[] = {2,4,5,18,19,21,22,23};

void setup() {
  Serial.begin(115200);
  for (int i; i<8; i++){
    pinMode(pin_arr[i], OUTPUT);
  }
}

void loop() {
  for (int i; i<8; i++){
    digitalWrite(pin_arr[i], HIGH);
    delay(500);
    digitalWrite(pin_arr[i], LOW);
  }
}
