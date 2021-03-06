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
uint8_t bRightness = 50;
int8_t mirror_shift = 6;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ringLeft, ringsize);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(ringRight, ringsize);
  /*declaring same variable to two data pins creates two identical
     rings
  */
  findLit(&(hringLeft[0]), ringsize, &(lit_hringLeft[0]));
}

void loop() {
  // now we start working on primary animation sequences
  uint8_t numCases = 3;
  uint8_t pickCase = random8(0, numCases);


//  switch (pickCase) {
//    case 0:
//      { // animation 1
//        calibrating();
//
//      }
//    case 1:
//      { // animation 2
//
//      }
//    case 2:
//      { // animation 3
//
//      }
//
//
//
//  }


}
