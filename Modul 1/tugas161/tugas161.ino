const int jumlahOutput = 8; // Deklarasi jumlah output
const int pinOutput[jumlahOutput] = {0, 1, 2, 3, 4, 5, 6, 7}; // Array pin output

void setup() {
  // Konfigurasi pin output
  UCSR0B=0x00;
  // PORTD = 0x00;
  for (int i = 0; i < jumlahOutput; i++) {
    pinMode(pinOutput[i], OUTPUT);
  }
  // Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop() {
    for(int i=0;i < jumlahOutput;i++){
      digitalWrite(pinOutput[i], HIGH); // Nyalakan LED
      delay(1000); // Delay untuk 1 detik
      digitalWrite(pinOutput[i], LOW); // Matikan LED
  }
}
