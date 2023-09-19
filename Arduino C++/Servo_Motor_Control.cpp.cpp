#include <Servo.h>

Servo myservo;
int potPin = A0;
int potValue = 0;

void setup() {
  myservo.attach(9);  // Attaches the servo on pin 9
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);  // Read potentiometer value
  int servoAngle = map(potValue, 0, 1023, 0, 180);  // Map value to servo angle (0-180 degrees)
  myservo.write(servoAngle);  // Set servo position
  delay(15);  // Delay for smoother control
}
