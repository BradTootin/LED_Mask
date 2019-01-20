// decided to start saving my debug codes they appear hear and are not normally run in the code

/*  // testing findLit
 *   
  fillRingRainbow(phringLeft, phringRight, pringLeft, pringRight, ringsize, 0, 100, 8);
  for (int i = 0; i < ringsize; i++) {
    if (i % 2 == 0) {
      (*(phringLeft + i)).v = 0; // clear them if they are odd
    }
  }
  copy_hsv2hsv(phringLeft, phringRight, ringsize);
  reverseHSV(phringRight, ringsize);
  copy_hrings2rings(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  FastLED.show();
  delay(500);
  findLit(phringLeft, ringsize, plit_hringLeft);

  for (int i = 0; i < ringsize; i++) {
    if (*(plit_hringLeft + i)) {
      (*(phringLeft + i)).h = 0; // turn it red
    }
    if (!*(plit_hringLeft + i)) {
      (*(phringLeft + i)).h = 80; // turn it greenish
      (*(phringLeft+i)).v = brightness; // turn it on
    }
  }
  copy_hsv2hsv(phringLeft, phringRight, ringsize);
  reverseHSV(phringRight, ringsize);
  copy_hrings2rings(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  FastLED.show();
  delay(500);
 */


 /*   // here we are testing find NumLit
  *    
  *    
  clear_leds(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  fillRingHue(phringLeft, phringRight, pringLeft, pringRight, ringsize, 100); // fill with nice green color
  // turn on the first 4
  FastLED.show();
  delay(500);
  for (int i = 0; i < random(1, 9) ; i++) {
    (*(phringLeft + i)).v = brightness;
  }
  copy_hsv2hsv(phringLeft, phringRight, ringsize);
  reverseHSV(phringRight, ringsize);
  copy_hrings2rings(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  FastLED.show();
  delay(500);
  uint8_t numLit = findNumLit(phringLeft, ringsize, plit_hringLeft);
  clear_leds(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  FastLED.show();
  delay(500);
  for (uint8_t i = numLit; i < ringsize ; i++) {
    (*(phringLeft + i)).v = brightness;
  }
  copy_hsv2hsv(phringLeft, phringRight, ringsize);
  reverseHSV(phringRight, ringsize);
  copy_hrings2rings(phringLeft, phringRight, pringLeft, pringRight, ringsize);
  FastLED.show();
  delay(500);
  */
