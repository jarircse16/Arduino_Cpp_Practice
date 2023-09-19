#include <IRremote.h>

int RECV_PIN = 11;  // Define the IR receiver pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    Serial.println(value, HEX);  // Print the received IR code in hexadecimal
    irrecv.resume();  // Receive the next value
  }
}
