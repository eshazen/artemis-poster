//----------------------------------------------------------------------------
// Example 1 : turn on 3 LEDs at a time, then rotate them
//----------------------------------------------------------------------------

#define NUM_LEDS 10
#define PIN A0

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel s = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);

//
// set all pixels in string to the same color
//
void setAllPixelColor( uint8_t r, uint8_t g, uint8_t b) {
  for( int i=0; i<NUM_LEDS; i++)
    s.setPixelColor( i, r, g, b);
}

//
// setup routine:  initialize LED string, set brightness
//
void setup() {
  s.begin();
  s.setBrightness(100);
  s.show();
}

#define DELAY_MS 250

//
// set 
void setPixelRange( uint8_t start, uint8_t end, uint8_t r, uint8_t g, uint8_t b) {
  if( start <= end)
    for( uint8_t i=start; i<=end; i++)
      s.setPixelColor( i, r, g, b);
  s.show();
}

//
// main loop
//
void loop() {

  setAllPixelColor( 0, 0, 0);	// all LEDs off
  s.show();
  delay( DELAY_MS);
  
  setPixelRange( 0, 2, 255, 0, 0);  // LEDs 0 to 2 RED
  delay( DELAY_MS);

  setPixelRange( 3, 5, 0, 255, 0);  // LEDs 3 to 5 GREEN
  delay( DELAY_MS);

  setPixelRange( 6, 9, 0, 0, 255);  // LEDs 6 to 9 BLUE
  delay( DELAY_MS);

}
