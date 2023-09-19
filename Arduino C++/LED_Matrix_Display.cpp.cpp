#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);  // Pins: DIN, CLK, LOAD, number of MAX7219 modules

void setup() {
  lc.shutdown(0, false);  // Wake up the MAX7219
  lc.setIntensity(0, 8);  // Set the brightness (0-15)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  String message = "Hello, Arduino!   ";
  
  for (int i = 0; i < message.length() * 8; i++) {
    lc.clearDisplay(0);
    for (int j = 0; j < 8; j++) {
      int charIndex = (i / 8) + j;
      if (charIndex < message.length()) {
        char c = message.charAt(charIndex);
        byte column = pgm_read_byte_near(font[c - 32] + j);
        lc.setColumn(0, j, column);
      }
    }
    delay(100);
  }
}
