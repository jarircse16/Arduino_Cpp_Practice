const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read LDR value (0-1023)
  Serial.print("Light Intensity: ");
  Serial.println(ldrValue);
  delay(1000);  // Delay for reading interval
}
