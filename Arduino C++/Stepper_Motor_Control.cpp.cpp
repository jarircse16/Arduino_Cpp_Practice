#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  myStepper.setSpeed(60);  // Set stepper motor speed (rpm)
}

void loop() {
  myStepper.step(100);  // Rotate 100 steps (1 revolution)
  delay(500);
  myStepper.step(-100);  // Rotate back 100 steps
  delay(500);
}
