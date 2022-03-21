#include <Arduino.h>

#define RED_LED D5   //led warna merah
#define GREEN_LED D6 //led warna hijau

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Contoh Program LED SOS 3 Warna");
}

void loop()
{
  // LED Merah
  for (int x = 0; x < 3; x++) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(150);                 
    digitalWrite(RED_LED, LOW); 
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++) {
    digitalWrite(RED_LED, HIGH);
    delay(400);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++) {
    digitalWrite(RED_LED, HIGH);
    delay(150);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }
  delay(1000);
  // LED Hijau
  for (int x = 0; x < 3; x++) {
    digitalWrite(GREEN_LED, HIGH);
    delay(150);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(GREEN_LED, HIGH);
    delay(400);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(GREEN_LED, HIGH);
    delay(150);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
  }
  delay(1000);
  // LED Biru
  for (int x = 0; x < 3; x++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(400);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  delay(100);
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  delay(1000);
}