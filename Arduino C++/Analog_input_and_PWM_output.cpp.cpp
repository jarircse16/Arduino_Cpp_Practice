const int potPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // Map to PWM range (0-255)

  analogWrite(ledPin, brightness); // Set LED brightness
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(100); // Delay for smoother response
}
