#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();        // Read humidity
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  delay(2000);  // Delay between readings
}
