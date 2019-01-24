void circshift_hsv(CHSV *hsv, int nShifts, bool dir) {
  CHSV dummy[ringsize]; // make copy
  copy_hsv2hsv(hsv, &(dummy[0]));
  if (dir == true) { // if we go clockwise
    nShifts = -1 * nShifts;
  }
  for (int8_t i = 0; i < ringsize; i++) {
    *(hsv + i) = dummy[(i + nShifts + ringsize) % ringsize];
  }
}

void circshift_rgb(CRGB *rgb, int nShifts, bool dir) {
  CRGB dummy[ringsize];
  copy_rgb2rgb(rgb, &(dummy[0]));
  if (dir == true) {
    nShifts = -1* nShifts;
  }
  for (int8_t i=0; i<ringsize; i++) {
    *(rgb+i) = dummy[(i+nShifts+ringsize)%ringsize];
  }
}


void circshift_rings(int nShifts, bool dir) {
  circshift_hsv(phringLeft,nShifts,dir);
  circshift_hsv(phringRight,nShifts,!dir);
  circshift_rgb(pringLeft,nShifts,dir);
  circshift_rgb(pringRight,nShifts,dir);
}

void cirshift_oring(int nShifts, bool dir) {
  circshift_hsv(poringLeft1,nShifts,dir);
  circshift_hsv(poringRight1,nShifts,!dir);
  circshift_hsv(poringLeft2,nShifts,!dir);
  circshift_hsv(poringRight2,nShifts,dir);
}

void hueShiftRings(uint8_t hueShift) {
  for (int8_t i=0; i<ringsize; i++) {
    (*(phringLeft+i)).h += hueShift;
    (*(phringRight+i)).h +=hueShift;
    *(pringLeft+i) = CHSV(*(phringLeft+i));
    *(pringRight+i) = CHSV(*(phringRight+i));
  }
}

void hueShiftOring(uint8_t hueShift) {
  for (int8_t i=0; i<ringsize; i++) {
  (*(poringLeft1+i)).h +=hueShift;
  (*(poringLeft2+i)).h +=hueShift;
  (*(poringRight1+i)).h +=hueShift;
  (*(poringRight2+i)).h +=hueShift;
  }
}

void send2Neighbor(CHSV *hsv, bool dir) {
  CHSV dummy[ringsize];
  copy_hsv2hsv(hsv, &(dummy[0]));
  // make a copy
  for (int8_t i = 0; i < ringsize; i++) {
    int8_t previous = (i - 1 + ringsize) % ringsize;
    uint8_t previousVal = dummy[previous].v;
    uint8_t currentVal = dummy[i].v;

    //clockwise case
    if (dir) {
      if (previousVal > 0 && currentVal == 0) {
        //if prev on and current off then current gets previous
        dummy[i] = *(hsv + previous);
      }
    }
    //CCW case
    if (!dir) {
      if (currentVal > 0 && previousVal == 0) { // current on previous off
        dummy[previous] = *(hsv + i);
      }
    }
    copy_hsv2hsv(&(dummy[0]), hsv); // copy back
  }
}

void blank2Neighbor(CHSV *hsv, bool dir) {
  CHSV dummy[ringsize];
  copy_hsv2hsv(hsv, &(dummy[0]));
  // make a copy
  for (int8_t i = 0; i < ringsize; i++) {
    int8_t previous = (i - 1 + ringsize) % ringsize;
    uint8_t previousVal = dummy[previous].v;
    uint8_t currentVal = dummy[i].v;
    //clockwise case
    if (dir) {
      if (previousVal == 0 && currentVal > 0) {
        //if prev off and current on then current gets previous
        dummy[i] = *(hsv + previous);
      }
    }
    //CCW case
    if (!dir) {
      if (currentVal == 0 && previousVal > 0) { // current off previous On
        dummy[previous] = *(hsv + i);
      }
    }
    copy_hsv2hsv(&(dummy[0]), hsv); // copy back
  }
}
