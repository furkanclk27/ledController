int relayPin = 8;  // Röleye bağlı pin

void setup() {
  Serial.begin(9600);        // Bluetooth modülü ile seri iletişim başlatılır
  pinMode(relayPin, OUTPUT); // Röle pinini çıkış olarak ayarla
  digitalWrite(relayPin, LOW); // Röleyi başlangıçta kapalı tut
}

void loop() {
  if (Serial.available() > 0) { // Seri port üzerinden veri olup olmadığını kontrol et
    char command = Serial.read(); // Gelen veriyi oku
    if (command == 'A') {        // 'A' komutu alındığında
      digitalWrite(relayPin, HIGH); // Röleyi aç (lambayı yak)
    }
    if (command == 'K') {        // 'K' komutu alındığında
      digitalWrite(relayPin, LOW);  // Röleyi kapat (lambayı söndür)
    }
  }
}
