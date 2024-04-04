//ADC internal nano adalah 10 bit, nilai maksimal 1024
#define ResADC 1023
#define Vin 4.68 //Voltage Nano di sekitar situ
#define analogPin A0
int value;
float voltage;
void setup() {
    Serial.begin(9600);
}
void loop() {
    value = analogRead(analogPin);
    voltage = (float)value/ResADC*Vin;
    Serial.println(voltage,3);
}
