void fillHue(uint8_t hueFill) {
  for (int8_t i=0; i<ringsize; i++) {
    (*(phringLeft+i)).h = hueFill;
    (*(phringLeft+i)).s = 255;
  }
  prepAll();
}

void fillRingRainbow(int8_t pixelStart, uint8_t hueStart, uint8_t hueStep) {
  for (int8_t i=0; i<ringsize; i++) {
    (*(phringLeft + (i+pixelStart)%ringsize)).h = hueStart+hueStep*i;
    (*(phringLeft + (i+pixelStart)%ringsize)).s = 255;
  }
  prepAll();  
}
