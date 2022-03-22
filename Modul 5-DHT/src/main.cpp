#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 5
#define RED_LED D1
#define GREEN_LED D3
#define BLUE_LED D4

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D5); 

void KelembabanSuhu()
{
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Pembacaan DHT11 gagal, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print("Temperatur: ");
  Serial.print((int)temperature);
  Serial.println(" °C ");
  Serial.print("Kelembapan : ");
  Serial.print((int)humidity);
  Serial.println(" % H");
  Serial.print("Status: ");
  if ((int)temperature <= 30) {
    Serial.println(F("Suhu Dingin"));
    digitalWrite(RED_LED, LOW); 
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(BLUE_LED, HIGH); 
    delay(1000);
  } else if ((int)temperature > 30 && (int)temperature <= 40) {
    Serial.println(F("Suhu Normal"));
    digitalWrite(RED_LED, LOW); 
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(BLUE_LED, LOW); 
    delay(1000);
  } else {
    Serial.println(F("Suhu Panas"));
    digitalWrite(RED_LED, HIGH); 
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(BLUE_LED, LOW); 
    delay(1000);
  }
  Serial.println("================================================");

  delay(1500);
}

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  Serial.println("Simple DHT and Convert");
  delay(1000);
}

void loop()
{
  KelembabanSuhu();
}