// artemis_example3 -- nested loops
// flash each LED Red 4 times

const int num_leds = 10;  // define a constant - number of LEDs

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
  for( int led = 0; led < num_leds; led++) {
    for( int i=0; i<4; i++) {
      s.setPixelColor( led, 255, 0, 0);  // set led to Red
      s.show();     // update the LEDs
      delay(100);   // delay 1/10 sec
      s.setPixelColor( led, 0, 0, 0);    // set led to off
      s.show();
      delay(100);
    }
    delay(500);
  }
}
