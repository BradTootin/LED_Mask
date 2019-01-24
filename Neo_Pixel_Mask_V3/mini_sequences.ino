void calibrating(uint8_t hueLow,uint8_t hueHigh) {
  bool clockways = random(0,2);
  for (int8_t i=0; i< random(3,5); i++) {
    clockways = !clockways;
    uint8_t nShifts = random8(7,12);
    uint8_t nOppositeShifts = random8(5,9);
    uint8_t nPixelsToBlink = random8(3,7);

    randomHueBlink(nPixelsToBlink,1,hueLow,hueHigh,75);
    rotateRing(clockways,nShifts,0,75);
    delay(200);
    rotateRing(!clockways, nShifts,0,75);
  }
}
