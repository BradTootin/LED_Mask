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

void copy_hrings2rings(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array) {
  copy_hsv2rgb(hsvleft, rgbleft, size_array);
  copy_hsv2rgb(hsvright, rgbright, size_array);
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

void clear_leds(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array) {
  clear_hsvarray(hsvleft, size_array);
  clear_hsvarray(hsvright, size_array);
  copy_hsv2rgb(hsvleft, rgbleft, size_array);
  copy_hsv2rgb(hsvright, rgbright, size_array);
}

void clear_orings(CHSV *hsvlefto1, CHSV *hsvlefto2, CHSV *hsvrighto1, CHSV *hsvrighto2, int8_t size_array) {
  clear_hsvarray(hsvlefto1, size_array);
  clear_hsvarray(hsvlefto2, size_array);
  clear_hsvarray(hsvrighto1, size_array);
  clear_hsvarray(hsvrighto2, size_array);
}

void clear_all(CHSV *hsvleft, CHSV *hsvright, CHSV *hsvlefto1, CHSV *hsvlefto2, CHSV *hsvrighto1,
               CHSV *hsvrighto2, CRGB *rgbleft, CRGB *rgbright, int8_t size_array) {
  clear_hsvarray(hsvleft, size_array);
  clear_hsvarray(hsvright, size_array);
  clear_orings(hsvlefto1, hsvlefto2, hsvrighto1, hsvrighto2, size_array);

}
