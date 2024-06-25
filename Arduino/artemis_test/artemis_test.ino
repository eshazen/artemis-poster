//----------------------------------------------------------------------------
// Dean's demo to pre-load on Arduinos
//----------------------------------------------------------------------------

#define NUM_LEDS 10
#define PIN A0

#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel s = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);


//
// flash one LED at specified color for specified time in ms
//
void flashColor(uint32_t c, uint16_t ms) {
  for (int i=0; i <s.numPixels(); i++)
    s.setPixelColor( i, c);
  s.show();
  delay( ms);
  for (int i=0; i <s.numPixels(); i++)
    s.setPixelColor( i, 0, 0, 0);
  s.show();
}

//void showLEDS () {
//  uint32_t temp;
//  uint32_t r, g, b;
//  for (int i=8; i<12; i++) {
//    temp = s.getPixelColor(i);
//    r = (temp >> 16) & 0xFF;
//    g = (temp >> 8) & 0xFF;
//    b = (temp) & 0xFF;
//    s.setPixelColor(i, g, r, b);
//  }
//  s.show();
//}

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

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< s.numPixels(); i++) {
      s.setPixelColor(i, Wheel(((i * 256 / s.numPixels()) + j) & 255));
    }
    s.show();
    delay(wait);
  }
}


uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return s.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return s.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return s.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void sweepCyan(uint8_t stop, uint16_t ms) {
  int i;
  for (i=0; i<stop; i++) {
    setAllPixelColor(0, i, i);
    s.show();
    delay(ms);
  }
  
  for ( ; i > 0; i--) {
    setAllPixelColor(0, i, i);
    s.show();
    delay(ms);
  }
}

void sweepMagenta(uint8_t stop, uint16_t ms) {
  int i;
  for (i=0; i<stop; i++) {
    setAllPixelColor(i, 0, i);
    s.show();
    delay(ms);
  }
  
  for ( ; i > 0; i--) {
    setAllPixelColor(i, 0, i);
    s.show();
    delay(ms);
  }
}


void sweepYellow(uint8_t stop, uint16_t ms) {
  int i;
  for (i=0; i<stop; i++) {
    setAllPixelColor(i, i, 0);
    s.show();
    delay(ms);
  }
  
  for ( ; i > 0; i--) {
    setAllPixelColor(i, i, 0);
    s.show();
    delay(ms);
  }
}

void loop() {

  for ( int i=0; i<4; i++ ) {
    for (int j=0; j<s.numPixels() + 2; j++) {
      s.setPixelColor(j, s.Color(0, 128, 0));
      s.setPixelColor(j-1, s.Color(0, 0, 128));
      s.setPixelColor(j-2, s.Color(128, 0, 0));
      delay(100);
      s.show();
      s.setPixelColor(j, s.Color(0, 0, 0));
      s.setPixelColor(j-1, s.Color(0, 0, 0));
      s.setPixelColor(j-2, s.Color(0, 0, 0));
    }
  } 
  delay (150);
  rainbowCycle(3); 
     
  sweepCyan(180,1);
  sweepMagenta(180,1);
  sweepYellow(180,1);
  
  delay (200);
  flashColor(s.Color(100, 100, 100), 150);
  delay (75);
  flashColor(s.Color(100, 100, 100), 150);  
  delay (200);
}
