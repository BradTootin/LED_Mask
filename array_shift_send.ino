/* CIRCLE SHIFTING */
void circshift_ring(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array, uint8_t nshifts, bool dir) {
  //TESTE
  circshift_hsv(hsvLeft, size_array, nshifts, dir);
  circshift_hsv(hsvRight, size_array, nshifts, !dir);
  circshift_rgb(rgbLeft, size_array, nshifts, dir);
  circshift_rgb(rgbRight, size_array, nshifts, !dir);
}
void circshift_hsv(CHSV *hsv, int8_t size_array, uint8_t nshifts, bool dir) { // TESTED
  CHSV dummy_hsv[size_array];
  copy_hsv2hsv(hsv, dummy_hsv, size_array);
  int8_t x;
  if (dir == true) {
    x = -1 * nshifts;
  }
  if (dir == false) {
    x = 1 * nshifts;
  }
  for (uint8_t i = 0; i < size_array; i++) {
    *(hsv + i) = dummy_hsv[(i + x + size_array) % size_array];
  }
}
void circshift_rgb(CRGB *rgb, int8_t size_array, uint8_t nshifts, bool dir) { // UNTESTED BUT ALSO UNUSED??
  CRGB dummy_rgb[size_array];
  copy_rgb2rgb(rgb, dummy_rgb, size_array);
  int8_t x;
  if (dir == true) {
    x = -1 * nshifts;
  }
  if (dir == false) {
    x = 1 * nshifts;
  }
  for (uint8_t i = 0; i < size_array; i++) {
    *(rgb + i) = dummy_rgb[(i + x + size_array) % size_array];
  }
}


/* reverse array */
void reverseHSV(CHSV *hsv, int8_t size_array) { //TESTED
  //make a copy
  CHSV dummyhsv[size_array];
  copy_hsv2hsv(hsv, &(dummyhsv[0]), size_array);
  // now reverse the order of the array
  for (int8_t i = 0; i < size_array; i++) {
    *(hsv + i) = dummyhsv[(size_array - i) % size_array];
  }
}

/* hue shifting */
void hueShiftRings(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array, uint8_t hueShift) {
  for (int8_t i = 0; i < size_array; i++) {
    (*(hsvLeft + i)).h += hueShift;
    (*(hsvRight + i)).h += hueShift;
  }
}
void hueShiftHSV(CHSV *hsv, int8_t size_array, uint8_t hueShift) {
  for (int8_t i = 0; i < size_array; i++) {
    (*(hsv + i)).h += hueShift;
  }
}


/* SENDING */
void send2Neighbor(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array, bool dir,
                   bool *litLeft, bool *litRight) { // TESTED
                    // if the LED is lit and the neighbor isn't then it makes the neighbor LIT (ie: it copies itself over)
  findLit(hsvLeft, size_array, litLeft);
  findLit(hsvRight, size_array, litRight);
  for (int8_t i = 0; i < size_array; i++) {
    if (dir == true) {
      if (*(litLeft + (i - 1 + size_array) % size_array) == true && *(litLeft + i) == false) {
        //if previous is on and this one is off
        *(hsvLeft + i) = *(hsvLeft + (i - 1 + size_array) % size_array);
        *(rgbLeft + i) = *(rgbLeft + (i - 1 + size_array) % size_array);
      }
      if (*(litRight + i) == true && *(litRight + (i - 1 + size_array) % size_array) == false) {
        // opposite case for Right side
        *(hsvRight + (i - 1 + size_array) % size_array) = *(hsvRight + i);
        *(rgbRight + (i - 1 + size_array) % size_array) = *(rgbRight + i);
      }
    }
    if (dir == false) {
      if (*(litLeft + i) == true && *(litLeft + (i - 1 + size_array) % size_array) == false) {
        //if current is on and previous is off
        *(hsvLeft + (i - 1 + size_array) % size_array) = *(hsvLeft + i);
        *(rgbLeft + (i - 1 + size_array) % size_array) = *(rgbLeft + i);
      }
      if (*(litRight + (i - 1 + size_array) % size_array) == true && *(litRight + i) == false) {
        // opposite case for Right side
        *(hsvRight + i) = *(hsvRight + (i - 1 + size_array) % size_array);
        *(rgbRight + i) = *(rgbRight + (i - 1 + size_array) % size_array);
      }
    }
  }
}

void blank2Neighbor(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array, bool dir,
                    bool *litLeft, bool *litRight) { // TESTED
  // If the LED is not lit then it makes its neighbor not lit
  findLit(hsvLeft, size_array, litLeft);
  findLit(hsvRight, size_array, litRight);
  int8_t x;
  if (dir == true) {
    x = 1;
  }
  if (dir == false) {
    x = -1;
  }
  for (int8_t i = 0; i < size_array; i++) {
    if (*(litLeft + i) == false) {
      if (*(litLeft + (i + x + size_array) % size_array) == true) {
        ((*(hsvLeft + (i + x + size_array) % size_array))).v = 0;
        *(rgbLeft + (i + x + size_array) % size_array) = CHSV(*(hsvLeft + (i + x + size_array) % size_array));
      }
    }
    if (*(litRight + i) == false) {
      if (*(litRight + (i - x + size_array) % size_array) == true) {
        ((*(hsvRight + (i - x + size_array) % size_array))).v = 0;
        *(rgbRight + (i - x + size_array) % size_array) = CHSV(*(hsvRight + (i - x + size_array) % size_array));
      }
    }
  }
}
