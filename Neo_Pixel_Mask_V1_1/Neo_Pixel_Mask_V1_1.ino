#include <FastLED.h>
#define DATA_PIN 6
#define DATA_PIN2 10
#define ONBOARD_PIN 8
#define ringsize 12

/* globals here*/
CRGB ringleft[ringsize], ringright[ringsize];
CRGB *pringleft = &(ringleft[0]), *pringright = &(ringright[0]);
CHSV hringleft[ringsize], hringright[ringsize];
CHSV oringleft1[ringsize], oringright1[ringsize], oringleft2[ringsize],oringright2[ringsize];
CHSV *phringleft = &(hringleft[0]), *phringright = &(hringright[0]);
CHSV *poringleft1 = &(oringleft1[0]), *poringright1=&(oringright1[0]), *poringleft2=&(oringleft2[0]);
CHSV *poringright2=&(oringright2[0]);
bool lit_hringleft[ringsize],lit_hringright[ringsize], lit_oringleft1[ringsize],lit_oringright1[ringsize];
bool lit_oringleft2[ringsize],lit_oringright2[ringsize];
bool *plit_hringleft=&(lit_hringleft[0]),*plit_hringright=&(lit_hringright[0]);
bool *plit_oringleft1=&(lit_oringleft1[0]),*plit_oringright1=&(lit_oringright1[0]);
bool *plit_oringleft2=&(lit_oringleft2[0]),*plit_oringright2=&(lit_oringright2[0]);
uint8_t brightness = 50;
int8_t mirror_shift = 6;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ringleft, ringsize);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(ringright, ringsize);
  /*declaring same variable to two data pins creates two identical
     rings
  */
  findLit(&(hringleft[0]), ringsize, &(lit_hringleft[0]));
}

void loop() {
  randomHueBlink(phringleft, phringright, pringleft, pringright, ringsize, 5, 5, plit_hringleft,plit_hringright, 75);
}
