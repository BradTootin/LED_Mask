void copy_hsv2hsv(CHSV *hsvsrc, CHSV *hsvdest, int8_t size_array) {
  for (int8_t i = 0; i < size_array; i++) {
    *(hsvdest + i) = *(hsvsrc + i);
  }
}

void copy_rgb2rgb(CRGB *rgbsrc, CRGB *rgbdest, int8_t size_array) {
  for (int8_t i = 0; i < size_array; i++) {
    *(rgbdest + i) = *(rgbsrc + i);
  }
}

void copy_hsv2rgb(CHSV *hsv, CRGB *rgb, int8_t size_array) {
  for (int8_t i = 0; i < size_array; i++) {
    *(rgb + i) = CHSV(*(hsv + i));
  }
}

void copy_hrings2rings(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array) {
  copy_hsv2rgb(hsvLeft, rgbLeft, size_array);
  copy_hsv2rgb(hsvRight, rgbRight, size_array);
}

void copy_ifSrcLit(CHSV *hsvSrc, CHSV *hsvDest, int8_t size_array, bool *srcLit) {
  for (int8_t i = 0; i < size_array; i++) {
    if (*(srcLit + i)) {
      *(hsvDest + i) = *(hsvSrc + i);
    }
  }
}

void clear_hsvarray(CHSV *hsv, int8_t size_array) {
  for (int8_t i = 0; i < size_array; i++) {
    (*(hsv + i)).v = 0;
    (*(hsv + i)).h = 0;
    (*(hsv + i)).s = 255;
  }
}

void clear_leds(CHSV *hsvLeft, CHSV *hsvRight, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array) {
  clear_hsvarray(hsvLeft, size_array);
  clear_hsvarray(hsvRight, size_array);
  copy_hsv2rgb(hsvLeft, rgbLeft, size_array);
  copy_hsv2rgb(hsvRight, rgbRight, size_array);
}

void clear_orings(CHSV *hsvLefto1, CHSV *hsvLefto2, CHSV *hsvRighto1, CHSV *hsvRighto2, int8_t size_array) {
  clear_hsvarray(hsvLefto1, size_array);
  clear_hsvarray(hsvLefto2, size_array);
  clear_hsvarray(hsvRighto1, size_array);
  clear_hsvarray(hsvRighto2, size_array);
}

void clear_all(CHSV *hsvLeft, CHSV *hsvRight, CHSV *hsvLefto1, CHSV *hsvLefto2, CHSV *hsvRighto1,
               CHSV *hsvRighto2, CRGB *rgbLeft, CRGB *rgbRight, int8_t size_array) {
  clear_hsvarray(hsvLeft, size_array);
  clear_hsvarray(hsvRight, size_array);
  clear_orings(hsvLefto1, hsvLefto2, hsvRighto1, hsvRighto2, size_array);

}
