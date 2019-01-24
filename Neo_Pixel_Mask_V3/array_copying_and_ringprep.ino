void copy_hsv2hsv(CHSV *hsvSrc, CHSV *hsvDest) {
  for (int8_t i=0; i<ringsize; i++) {
    *(hsvDest+i)= *(hsvSrc+i);
  }  
}

void copy_hsv2rgb(CHSV *hsv, CRGB *rgb) {
  for (int8_t i=0; i<ringsize; i++) {
    *(rgb+i) = CHSV(*(hsv+i));
  }
}

void copy_rgb2rgb(CRGB *rgbSrc, CRGB *rgbDest) {
  for (int8_t i=0; i<ringsize; i++) {
    *(rgbDest+i)= *(rgbSrc+i);
  }  
}

void copyIfSrcLit(CHSV *hsvSrc, CHSV *hsvDest) {
  for (int8_t i=0; i<ringsize; i++) {
    if( (*(hsvSrc+i)).v > 0) {
      (*hsvDest+i) = *(hsvSrc+i);
    } 
  }
}

void reverse_hsv(CHSV *hsv) {
  // make a copy
  CHSV dummy[ringsize];
  copy_hsv2hsv(hsv, &(dummy[0]));
  for (int8_t i=0; i<ringsize; i++) {
    *(hsv+i) = dummy[(i+ringsize-1)%ringsize];
  }
}

void clear_hsv(CHSV *hsv) {
  for (int8_t i=0; i<ringsize; i++) {
    (*(hsv+i)).v = 0;
    (*(hsv+i)).s = 255;
  }
}

void clear_leds() {
  clear_hsv(phringLeft);
  clear_hsv(phringRight);  
}

void clear_oring() {
  clear_hsv(poringLeft1);
  clear_hsv(poringRight1);
  clear_hsv(poringLeft2);
  clear_hsv(poringRight2);
}

void prepAll() {
  prepMirror();
  prepLeds();
}

void prepLeds() {
  copy_hsv2rgb(phringLeft,pringLeft);
  copy_hsv2rgb(phringRight,pringRight);
}

void prepMirror() {
  copy_hsv2hsv(phringLeft,phringRight);
  circshift_hsv(phringRight,3,true);
  reverse_hsv(phringRight);
}

void prepOring() {
  copy_hsv2hsv(poringLeft1,poringRight1);
  reverse_hsv(poringRight1);
  copy_hsv2hsv(poringLeft2,poringRight2);
  reverse_hsv(poringRight2);  
}
