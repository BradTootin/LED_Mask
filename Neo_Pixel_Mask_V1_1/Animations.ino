/* Blinking / Filling With Show */
void randomHueBlink(CHSV *hsvLeft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array,
                    uint8_t num_pixels, uint8_t num_blinks, bool *litleft, bool*litright, int wait) {
  for (uint8_t j = 0; j < num_blinks; j++) {
    clear_leds(hsvLeft, hsvright, rgbleft, rgbright, size_array);
    for (int8_t i = 0; i < num_pixels; i++) { //fill in specified random number of pixels
      findLit(hsvLeft, size_array, litleft);
      uint8_t ind = random8(0, size_array);
      while (*(litleft + ind)) {
        *(hsvLeft + ind) = CHSV(random8(), 255, brightness);
      }
    }
    copy_hsv2hsv(hsvLeft, hsvright, size_array);
    circshift_hsv(hsvright, size_array, mirror_shift, true); // shift to counteract misalignment in mask assembly
    copy_hrings2rings(hsvLeft, hsvright, rgbleft, rgbright, size_array);
    FastLED.show();
    delay(wait);
    clear_leds(hsvLeft,hsvright,rgbleft,rgbright,size_array);
    FastLED.show();
    delay(wait);
  }
}

void randomBlinkCurrentHue(CHSV *hsvLeft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array, uint8_t numOn,
                           bool *litleft, bool *litright, int wait) { // using the hues values randomly turns on
  uint8_t numlit;
  numlit = findNumLit(hsvLeft, size_array, litleft);
  while (numlit != numOn) { //as long as the number lit isn't the number we want lit
    int8_t ind = random8(0, size_array); // pick a random pixel on left side mask
    if (!*(litleft + ind)) { // if it's not lit
      (*(hsvLeft + ind)).v = brightness; // then make it lit motherfucker
      copy_hsv2hsv(hsvLeft, hsvright, size_array);
      circshift_hsv(hsvright, size_array, mirror_shift, true); //copy and appropriately shift the right one because I can't assemble it correctly
      copy_hrings2rings(hsvLeft, hsvright, rgbleft, rgbright, size_array);
      FastLED.show(); //show it
      delay(wait); // delay
    } //doesn't show or delay if it's not lit so it lights up one at a time
    numlit = findNumLit(hsvLeft, size_array, litleft);
  }
}
void randomNumOn(CHSV * hsvLeft, CHSV * hsvright, CRGB * rgbleft, CRGB * rgbright, int8_t size_array, uint8_t numOn,
                 bool * litleft, bool * litright, int wait) { // using the hues values randomly turns on some number of pixels all at once
  uint8_t numlit;
  numlit = findNumLit(hsvLeft, size_array, litleft);
  while (numlit != numOn) { //as long as the number lit isn't the number we want lit
    int8_t ind = random8(0, size_array); // pick a random pixel on left side mask
    if (!*(litleft + ind)) { // if it's not lit
      (*(hsvLeft + ind)).v = brightness; // then make it lit motherfucker
      copy_hsv2hsv(hsvLeft, hsvright, size_array);
      circshift_hsv(hsvright, size_array, mirror_shift, true); //copy and appropriately shift the right one because I can't assemble it correctly
      copy_hrings2rings(hsvLeft, hsvright, rgbleft, rgbright, size_array);

    }
    numlit = findNumLit(hsvLeft, size_array, litleft);
  }
  FastLED.show(); //show it
  delay(wait); // delay

}

/* Filling with no show */
void fillRingHue(CHSV * hsvLeft, CHSV * hsvright, CRGB * rgbleft, CRGB * rgbright, int8_t size_array, uint8_t hueFill) {
  for (int8_t i = 0; i < size_array; i++) {
    (*(hsvLeft + i)).h = hueFill;
    (*(hsvright + i)).h = hueFill;
  }
  copy_hrings2rings(hsvLeft, hsvright, rgbleft, rgbright, size_array);
}

void animateORings(CHSV * hsvLeft, CHSV * hsvRight, CHSV * hsvOLeft1, CHSV * hsvOLeft2, CHSV * hsvORight1, CHSV * hsvORight2,
                   CRGB * rgbleft, CRGB * rgbright, int8_t size_array, bool dirO1, bool dirO2, bool * litLeftO1, bool * litLeftO2,
                   bool * litRightO1, bool * litRightO2, bool leaveTrail, uint8_t hueShift, uint8_t nShifts, int wait) {
  // make a copy of the rings
  CHSV dummyLeft[size_array], dummyRight[size_array];
  copy_hsv2hsv(hsvLeft, dummyLeft, size_array);
  copy_hsv2hsv(hsvRight, dummyRight, size_array);
  for (int8_t i = 0; i < nShifts; i++) { // animation loop
    findLit(hsvOLeft1, size_array, litLeftO1); // find if a lot of things are lit
    findLit(hsvOLeft2, size_array, litLeftO2);
    findLit(hsvORight1, size_array, litRightO1);
    findLit(hsvORight2, size_array, litRightO2);
    copy_ifSrcLit(hsvOLeft1, hsvLeft, size_array, litLeftO1); // copy over if they are lit
    copy_ifSrcLit(hsvOLeft2, hsvLeft, size_array, litLeftO2); // 2 overwrites 1
    copy_ifSrcLit(hsvORight1, hsvRight, size_array, litRightO1);
    copy_ifSrcLit(hsvORight2, hsvRight, size_array, litRightO2);
    FastLED.show();
    delay(wait);
    circshift_hsv(hsvOLeft1, size_array, 1, dirO1); // circ shift the Orings by 1
    circshift_hsv(hsvOLeft2, size_array, 1, dirO2);
    circshift_hsv(hsvORight1, size_array, 1, !dirO1);
    circshift_hsv(hsvORight2, size_array, 1, !dirO2);



  }
}

void fill_ring_rainbow(CHSV * hsvLeft, CHSV * hsvright, CRGB * rgbleft, CRGB * rgbright, int8_t size_array, int8_t pixelStart , uint8_t hueStart, uint8_t hueStep) {
  for (int8_t i = 0; i < size_array; i++) {
    *(hsvLeft + (i + pixelStart) % size_array) = CHSV(hueStart + hueStep * i, 255, brightness);
  }
  copy_hsv2hsv(hsvLeft, hsvright, size_array);
  circshift_hsv(hsvright, size_array, mirror_shift, true);
  copy_hrings2rings(hsvLeft, hsvright, rgbleft, rgbright, size_array);
}

/* Rotation and over animation */
void rotate_ring(CHSV * hsvLeft, CHSV * hsvRight, CRGB * rgbleft, CRGB * rgbright, int8_t size_array, bool dir,
                 uint8_t nshifts, uint8_t hueShift, int wait) {
  for (uint8_t i = 0; i < nshifts; i++) {
    circshift_ring(hsvLeft, hsvRight, rgbleft, rgbright, size_array, 1, dir);
    hueShiftRings(hsvLeft, hsvRight, rgbleft, rgbright, size_array, hueShift);
    copy_hrings2rings(hsvLeft, hsvRight, rgbleft, rgbright, size_array);
    FastLED.show();
    delay(wait);
  }
}
