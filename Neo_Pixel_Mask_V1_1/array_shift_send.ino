/* CIRCLE SHIFTING */
void circshift_ring(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array, uint8_t nshifts, bool dir) {
  circshift_hsv(hsvleft, size_array, nshifts, dir);
  circshift_hsv(hsvright, size_array, nshifts, !dir);
  circshift_rgb(rgbleft, size_array, nshifts, dir);
  circshift_rgb(rgbright, size_array, nshifts, !dir);
}
void circshift_hsv(CHSV *hsv, int8_t size_array, uint8_t nshifts, bool dir) {
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
void circshift_rgb(CRGB *rgb, int8_t size_array, uint8_t nshifts, bool dir) {
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

void reverseHSV(CHSV *hsv, int8_t size_array) {
  //make a copy
  CHSV dummyhsv[size_array];
  copy_hsv2hsv(hsv, &(dummyhsv[0]),size_array);
  // now reverse the order of the array
  for (int8_t i=0; i<size_array; i++) {
    *(hsv+i) = dummyhsv[(size_array-i)%size_array];
  }
}

/* hue shifting */
void hueShiftRings(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array, uint8_t hueShift) {
  for (int8_t i=0; i<size_array; i++) {
    (*(hsvleft+i)).h += hueShift;
    (*(hsvright+i)).h += hueShift;
  }
}
void hueShiftHSV(CHSV *hsv, int8_t size_array, uint8_t hueShift) {
  for (int8_t i=0; i<size_array; i++) {
    (*(hsv+i)).h += hueShift;
  }
}


/* SENDING */
void send2Neighbor(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array, bool dir,
                   bool *litleft, bool *litright) {
  findLit(hsvleft, size_array, litleft);
  findLit(hsvright, size_array, litright);
  for (int8_t i = 0; i < size_array; i++) {
    if (dir == true) {
      if (*(litleft + (i - 1 + size_array) % size_array) == true && *(litleft + i) == false) {
        //if previous is on and this one is off
        *(hsvleft + i) = *(hsvleft + (i - 1 + size_array) % size_array);
        *(rgbleft + i) = *(rgbleft + (i - 1 + size_array) % size_array);
      }
      if (*(litright + i) == true && *(litright + (i - 1 + size_array) % size_array) == false) {
        // opposite case for right side
        *(hsvright + (i - 1 + size_array) % size_array) = *(hsvright + i);
        *(rgbright + (i - 1 + size_array) % size_array) = *(rgbright + i);
      }
    }
    if (dir == false) {
      if (*(litleft + i) == true && *(litleft + (i - 1 + size_array) % size_array) == false) {
        //if current is on and previous is off
        *(hsvleft + (i - 1 + size_array) % size_array) = *(hsvleft + i);
        *(rgbleft + (i - 1 + size_array) % size_array) = *(rgbleft + i);
      }
      if (*(litright + (i - 1 + size_array) % size_array) == true && *(litright + i) == false) {
        // opposite case for right side
        *(hsvright + i) = *(hsvright + (i - 1 + size_array) % size_array);
        *(rgbright + i) = *(rgbright + (i - 1 + size_array) % size_array);
      }
    }
  }
}

void blank2Neighbor(CHSV *hsvleft, CHSV *hsvright, CRGB *rgbleft, CRGB *rgbright, int8_t size_array, bool dir,
                    bool *litleft, bool *litright) {
  findLit(hsvleft,size_array,litleft);
  findLit(hsvright,size_array,litright);
  int8_t x; 
  if (dir==true) {
    x=1;
  }
  if (dir==false) {
    x=-1;
  }
  for (int8_t i=0; i<size_array; i++) {
    if (*(litleft+i) == false) {
      if (*(litleft+(i+x+size_array)%size_array) ==true) {
        ((*(hsvleft+(i+x+size_array)%size_array))).v = 0;
        *(rgbleft+(i+x+size_array)%size_array)= CHSV(*(hsvleft+(i+x+size_array)%size_array));
      }
    }
    if (*(litright+i) == false) {
      if (*(litright+(i-x+size_array)%size_array)==true) {
        ((*(hsvright+(i-x+size_array)%size_array))).v = 0;
        *(rgbright+(i-x+size_array)%size_array)= CHSV(*(hsvright+(i-x+size_array)%size_array));
      }
    }
  }
}
