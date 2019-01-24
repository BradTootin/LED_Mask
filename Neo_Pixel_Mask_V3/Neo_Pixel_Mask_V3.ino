#include <FastLED.h>
#define DATA_PIN 6
#define DATA_PIN2 9
#define ONBOARD_PIN 8
#define ringsize 12


/* ------ GLOBALS ------ */
CRGB ringLeft[ringsize], ringRight[ringsize];
CRGB *pringLeft = &(ringLeft[0]), *pringRight = &(ringRight[0]);
CHSV hringLeft[ringsize], hringRight[ringsize];
CHSV *phringLeft = &(hringLeft[0]), *phringRight = &(hringRight[0]);
CHSV oringLeft1[ringsize], oringLeft2[ringsize];
CHSV oringRight1[ringsize], oringRight2[ringsize];
CHSV *poringLeft1 = &(oringLeft1[0]), *poringLeft2 = &(oringLeft2[0]);
CHSV *poringRight1 = &(oringRight1[0]),*poringRight2 = &(oringRight2[0]);
bool lit_hringLeft[ringsize], lit_hringRight[ringsize],
     lit_oringLeft1[ringsize], lit_oringLeft2[ringsize],
     lit_oringRight1[ringsize], lit_oringRight2[ringsize];
bool *plit_hringLeft = &(lit_hringLeft[0]), *plit_hringRight = &(lit_hringRight[0]);
bool *plit_oringLeft1 = &(lit_oringLeft1[0]), *plit_oringLeft2 = &(lit_oringLeft2[0]), *plit_oringRight1 = &(lit_oringRight1[0]);
bool *plit_oringRight2 = &(lit_oringRight2[0]);
uint8_t brightness = 50;
int8_t mirror_shift = 0;
//int8_t unLitList[ringsize];


void setup() {
  FastLED.addLeds <NEOPIXEL, DATA_PIN>(ringLeft, ringsize);
  FastLED.addLeds <NEOPIXEL, DATA_PIN2>(ringLeft, ringsize);
  clear_leds();
  prepAll();

}

void loop() {
  randomHueBlink(5,5,104,200,75);
  rotateRing(true,12,10,75);
  randomHueBlink(5,5,0,96,75);
  rotateRing(false,12,10,75);
  randomHueBlink(5,5,200,255,75);
  rotateRing(false,12,10,75);

}
