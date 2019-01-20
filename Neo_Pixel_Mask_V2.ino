#include <FastLED.h>
#define DATA_PIN 6
#define DATA_PIN2 10
#define ONBOARD_PIN 8
#define ringsize 12

/* globals here*/
CRGB ringLeft[ringsize], ringRight[ringsize];
CRGB *pringLeft = &(ringLeft[0]), *pringRight = &(ringRight[0]);
CHSV hringLeft[ringsize], hringRight[ringsize];
CHSV oringLeft1[ringsize], oringRight1[ringsize], oringLeft2[ringsize], oringRight2[ringsize];
CHSV *phringLeft = &(hringLeft[0]), *phringRight = &(hringRight[0]);
CHSV *poringLeft1 = &(oringLeft1[0]), *poringRight1 = &(oringRight1[0]), *poringLeft2 = &(oringLeft2[0]);
CHSV *poringRight2 = &(oringRight2[0]);
bool lit_hringLeft[ringsize], lit_hringRight[ringsize], lit_oringLeft1[ringsize], lit_oringRight1[ringsize];
bool lit_oringLeft2[ringsize], lit_oringRight2[ringsize];
bool *plit_hringLeft = &(lit_hringLeft[0]), *plit_hringRight = &(lit_hringRight[0]);
bool *plit_oringLeft1 = &(lit_oringLeft1[0]), *plit_oringRight1 = &(lit_oringRight1[0]);
bool *plit_oringLeft2 = &(lit_oringLeft2[0]), *plit_oringRight2 = &(lit_oringRight2[0]);
uint8_t brightness = 50;
int8_t mirror_shift = 6;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ringLeft, ringsize);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(ringRight, ringsize);
  /*declaring same variable to two data pins creates two identical
     rings
  */
  clear_leds(phringLeft, phringRight, pringLeft, pringRight, ringsize);

}

void loop() {
  // testing blank to neighbor and send to neighbor
  for (int8_t i = 0; i < 4; i++) {
    *(phringLeft + random(0, 12)) = CHSV(random8(), 255, brightness);
    copy_hsv2hsv(phringLeft, phringRight, ringsize);
    reverseHSV(phringRight, ringsize);
    copy_hrings2rings(phringLeft, phringRight, pringLeft, pringRight, ringsize);
    FastLED.show();
    delay(75);
  }
  for (int8_t i = 0; i < 3; i++) {
    send2Neighbor(phringLeft, phringRight, pringLeft, pringRight, ringsize, true, plit_hringLeft, plit_hringRight);
    FastLED.show();
    delay(75);
  }
  for (int8_t i=0; i<6; i++ ) {
    blank2Neighbor(phringLeft,phringRight,pringLeft,pringRight,ringsize, true, plit_hringLeft,plit_hringRight);
    FastLED.show();
    delay(75);
  }
  clear_leds(phringLeft,phringRight,pringLeft,pringRight,ringsize);

  // testing randomHueBlink
  randomHueBlink(phringLeft,phringRight,pringLeft,pringRight,ringsize,4, 8, plit_hringLeft,plit_hringRight, 100);


}
