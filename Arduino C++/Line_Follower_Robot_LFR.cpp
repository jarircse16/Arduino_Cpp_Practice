// Include necessary libraries
#include <Arduino.h>

// Define the pin connections for the IR sensors
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Define threshold values for the sensors (adjust these as needed)
#define SENSOR_THRESHOLD 500

// Define motor control pins
#define LEFT_MOTOR_FORWARD 2
#define LEFT_MOTOR_BACKWARD 3
#define RIGHT_MOTOR_FORWARD 4
#define RIGHT_MOTOR_BACKWARD 5

void setup() {
  // Initialize motor control pins as OUTPUT
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  
  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);

  // Debugging: print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensorValue);

  // Check if both sensors detect a white surface
  if (leftSensorValue < SENSOR_THRESHOLD && rightSensorValue < SENSOR_THRESHOLD) {
    // Both sensors detect white, move forward
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  } else {
    // At least one sensor does not detect white, stop
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  }
}
