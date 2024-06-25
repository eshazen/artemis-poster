// artemis_example2 -- fade all LEDs up and down

// some magic to let us talk to the LEDs
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel s = Adafruit_NeoPixel(20, A0, NEO_RGB + NEO_KHZ800);

// setup function called once
void setup() {
  s.begin();             // initialize the LED code
  s.setBrightness(128);  // set maximum brightness
}

// new function to set all the LEDs to the same color
void setSameColor( int red, int green, int blue) {
  for( int i=0; i<25; i++) {  // loop from 0 to 24
    s.setPixelColor( i, red, green, blue);  // set each LED color
  }  
  s.show();  // update the LEDs
}

// main loop runs over and over
void loop() {
  // loop from 0 to 255 to fade up LED
  for( int bright=0; bright<256; bright++) {
    setSameColor( bright, bright, bright);
    delay(2);
  } 
  // loop from 255 back to 0
  for( int bright=255; bright>=0; bright--) {
    setSameColor( bright, bright, bright);
    delay(2);
  } 
}
