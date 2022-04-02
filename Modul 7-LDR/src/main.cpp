#include <Arduino.h>
#include <SimpleDHT.h>

#define sensorLDR A0
int ldr;

#define pinDHT 5
byte temperature = 0;
byte humidity = 0;
SimpleDHT11 dht11(D5); 

#define RED_LED D7
#define BLUE_LED D6

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.println("Lampu Otomatis berdasarkan Sensor LDR dan DHT");
  delay(3000);
}

void loop() {
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Pembacaan DHT11 gagal, err=");
    Serial.println(err);
    delay(1000);
    return;
  }
  
  ldr = analogRead(sensorLDR);

  Serial.println("=====================================");
  Serial.print("Nilai LDR : ");
  Serial.println(ldr);
  Serial.print("Nilai suhu : ");
  Serial.println(temperature);
  Serial.print("Nilai kelembaban : ");
  Serial.println(humidity);

  if (ldr < 900) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(4000);

    Serial.println("LAMPU MERAH MENYALA");
  }
  else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    delay(500);

    Serial.println("LAMPU BIRU BERKEDIP_KEDIP");
  }
  delay(2000);
}