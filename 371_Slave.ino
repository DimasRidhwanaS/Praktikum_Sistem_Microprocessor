char dataSlave;
void setup() {
    Serial.begin(9600);
}
void loop() {
    dataSlave = Serial.read();
    delay(1000);
}