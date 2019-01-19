void calibrating() {
  bool clockways = random(0,2);
  for(int8_t i=0; i<2; i++) {
    clockways = !clockways;
    uint8_t nShifts = random8(3,6);
    uint8_t nOppositeShifts = random8(3,6);
    uint8_t nPixelsToBlink = random8(3,7);
    uint8_t firstDelay = random8(40,80);
    uint8_t secondDelay = random8(40,80);

    randomHueBlink(phringleft,phringright,pringleft,pringright,ringsize, nPixelsToBlink, 
    1,plit_hringleft,plit_hringright,250);
    rotate_ring(phringleft,phringright,pringleft,pringright,ringsize,clockways,nShifts,0,firstDelay);
    rotate_ring(phringleft,phringright,pringleft,pringright,ringsize,!clockways,nOppositeShifts,0,secondDelay);
    
  }
}

void calibrating2(int8_t nRepeats) {
  bool clockways = random8(0,2);
  for(int8_t i=0; i<nRepeats; i++) {
    clockways = !clockways;
    uint8_t nShifts = random8(3,6);
    uint8_t nOppositeShifts = random8(3,6);
    uint8_t nPixelsToBlink = random8(3,7);

    
  }
}
