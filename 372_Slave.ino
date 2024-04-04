#define pinLED 5
char dataSlave;
void setup() {
//Pilih nilai port serial
Serial.begin(9600);
//Inisialisasi port output
pinMode(pinLED,OUTPUT);
}
void loop() {
    dataSlave = Serial.read();
    
    if(dataSlave == '1'){
        digitalWrite(pinLED,HIGH);
    }
    else{
        digitalWrite(pinLED,LOW);
    }
    delay(250);
}