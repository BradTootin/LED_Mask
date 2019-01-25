void randomHueBlink(uint8_t nPixels, uint8_t nBlinks, uint8_t hue_low, uint8_t hue_high, int wait) {
  int8_t unLitList[ringsize];
  int8_t numLit = 0;
  int8_t index=0;
  int8_t pixel=0;
  for (int8_t i=0; i<nBlinks; i++) {
    clear_leds();
    prepLeds();
    FastLED.show();
    delay(wait);
    createUnlitList(phringLeft,&(unLitList[0]));
    numLit = findNumLit(phringLeft);
      while(numLit < nPixels) { // written in such a way that we are guaranteed to pick an unlit pixel 
        // accomplished by randomly selecting from a list of unlit pixels
        index = random8(0,(ringsize-numLit));
        pixel = unLitList[index];
        (*(phringLeft+pixel)).v = brightness;
        (*(phringLeft+pixel)).h = random8(hue_low,hue_high);
        createUnlitList(phringLeft,&(unLitList[0]));
        numLit = findNumLit(phringLeft);
      }
    prepAll();
    FastLED.show();
    delay(wait);
  }
}

void rotateRing(bool dir, int nShifts, uint8_t hueShift, int wait) {
  for (uint8_t i = 0; i < nShifts; i++) {
    circshift_rings(1, dir);
    if (hueShift != 0) {
      hueShiftRings(hueShift);
    }
    FastLED.show();
    delay(wait);
  }
}

void animateOring(bool leaveTrail, bool dir,uint8_t hueShift, int nShifts, int wait) {
  CHSV dummyLeft[ringsize], dummyRight[ringsize];
  copy_hsv2hsv(phringLeft, &(dummyLeft[0]));
  copy_hsv2hsv(phringRight, &(dummyRight[0]));
  for (int8_t i = 0; i < nShifts; i++) {
    copyIfSrcLit(poringLeft1, phringLeft);
    copyIfSrcLit(poringLeft2, phringLeft);
    copyIfSrcLit(poringRight1, phringRight);
    copyIfSrcLit(poringRight2, phringRight);
    prepLeds();
    FastLED.show();
    delay(wait);
    hueShiftOring(hueShift);
    circshift_oring(1,dir);
    if (leaveTrail == false) {
      copy_hsv2hsv(&(dummyLeft[0]), phringLeft);
      copy_hsv2hsv(&(dummyRight[0]), phringRight);
    }
  }
}

void fanOut(bool dir, int wait) {
  bool itsLitLeft = queryItsLit(phringLeft);
  bool itsLitRight = queryItsLit(phringRight);
  while(!itsLitLeft || !itsLitRight) {
    send2Neighbor(phringLeft, dir);
    send2Neighbor(phringRight,!dir);
    prepLeds();
    FastLED.show();
    itsLitLeft = queryItsLit(phringLeft);
    itsLitRight = queryItsLit(phringRight);
    delay(wait);
  }
}
void foldIn(bool dir, int wait) {
  bool itsLitLeft = queryItsLit(phringLeft);
  bool itsLitRight = queryItsLit(phringRight);
  if (itsLitLeft || itsLitRight) {
    return;
  }
  bool itsDarkLeft = queryItsDark(phringLeft);
  bool itsDarkRight = queryItsDark(phringRight);

  while(!itsDarkLeft || !itsDarkRight) {
    blank2Neighbor(phringLeft, dir);
    blank2Neighbor(phringRight,!dir);
    prepLeds();
    FastLED.show();
    itsDarkLeft = queryItsDark(phringLeft);
    itsDarkRight = queryItsDark(phringRight);
    delay(wait);
  }
  
}
