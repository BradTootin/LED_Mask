void  calibrating() {
  bool clockways = random(0, 2);
  for (int8_t i = 0; i < 2; i++) {
    clockways = !clockways;
    uint8_t nShifts = random8(3, 6);
    uint8_t nOppositeShifts = random8(3, 6);
    uint8_t nPixelsToBlink = random8(3, 7);
    uint8_t firstDelay = random8(40, 80);
    uint8_t secondDelay = random8(40, 80);

    randomHueBlink(phringLeft, phringRight, pringLeft, pringRight, ringsize, nPixelsToBlink,
                   1, plit_hringLeft, plit_hringRight, 250);
    rotateRing(phringLeft, phringRight, pringLeft, pringRight, ringsize, clockways, nShifts, 0, firstDelay);
    rotateRing(phringLeft, phringRight, pringLeft, pringRight, ringsize, !clockways, nOppositeShifts, 0, secondDelay);

  }
}

void bounce_ring(uint8_t hueShift) {
// okay so we take what the rings currently are and rotate back and forth a few times
  bool clockways = random8(0,2);
  uint8_t nBounces = random8(2,5);
   for (uint8_t i=0; i<nBounces; i++) {
      rotateRing(phringLeft,phringRight,pringLeft,pringRight,ringsize,clockways, ringsize, hueShift,75);
      clockways = !clockways;
      rotateRing(phringLeft,phringRight,pringLeft,pringRight,ringsize,clockways, ringsize, hueShift,75);
}
}
