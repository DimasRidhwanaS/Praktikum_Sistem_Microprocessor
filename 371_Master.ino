char dataMaster1 = '1';
char dataMaster2 = '0';
void setup() {
    Serial.begin(9600);
}
void loop() {
    Serial.write(dataMaster1);
    delay(1000);
    Serial.write(dataMaster2);
    delay(1000);
}