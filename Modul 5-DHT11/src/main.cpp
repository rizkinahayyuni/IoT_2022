#include <Arduino.h>
#include <DHT.h>
#define DHTTYPE DHT11
DHT dht(D1, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Menggunakan DHT11");
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.println("===================================================");
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F(" %"));
  Serial.println("___________________________________________________");
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C | "));
  Serial.print(f);
  Serial.print(F("°F | "));
  Serial.print((0.8 * double(t)));
  Serial.print(F("°R | "));
  Serial.print((t + 273.15));
  Serial.println(F("°K"));
  Serial.println("___________________________________________________");
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C | "));
  Serial.print(hif);
  Serial.print(F("°F | "));
  Serial.print((0.8 * double(hic)));
  Serial.print(F("°R | "));
  Serial.print((hic  + 273.15));
  Serial.println(F("°K"));
  Serial.println("===================================================");
}