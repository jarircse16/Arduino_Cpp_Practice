int lightSensorPin = A0; // Light sensor connected to analog pin A0
int ledPin = 13;         // LED connected to digital pin 13
int sensorValue = 0;     // Variable to store sensor readings

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  sensorValue = analogRead(lightSensorPin); // Read the sensor value

  if (sensorValue > 500) {
    digitalWrite(ledPin, HIGH); // Turn on the LED when it's bright
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED when it's dark
  }
}
