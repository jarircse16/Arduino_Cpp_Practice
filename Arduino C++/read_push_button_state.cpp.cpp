int buttonPin = 2; // Push button connected to digital pin 2
int ledPin = 13;   // LED connected to digital pin 13
int buttonState = 0; // Variable to store the button state

void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as an output
  pinMode(buttonPin, INPUT); // Set the button pin as an input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED when the button is pressed
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED when the button is not pressed
  }
}
