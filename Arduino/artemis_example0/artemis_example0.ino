// Simple example
// set first three leds to Red, Green, Pink and blink them

// some magic to let us talk to the LEDs
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel s = Adafruit_NeoPixel(20, A0, NEO_RGB + NEO_KHZ800);

// setup function called once
void setup() {
  s.begin();             // initialize the LED code
  s.setBrightness(128);  // set maximum brightness
}

// main loop runs over and over
void loop() {
  s.setPixelColor( 0, 255, 0, 0);    // First LED to RED only
  s.setPixelColor( 1, 0, 255, 0);    // Second LED to GREEN only
  s.setPixelColor( 2, 255, 0, 255);  // Third LED to RED+BLUE = PINK
  s.show();      // "make it happen" - update the LEDs
  delay(500);    // delay 500 ms (1/2 a second)
  s.setPixelColor( 0, 0, 0, 0);  // First LED off
  s.setPixelColor( 1, 0, 0, 0);  // Second LED off
  s.setPixelColor( 2, 0, 0, 0);  // Third LED off
  s.show();      // "make it happen" - update the LEDs
  delay(500);
}
