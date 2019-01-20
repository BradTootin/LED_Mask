void findLit(CHSV *hsv,int8_t size_array, bool *lit_array) { // TESTED appears to work
  for (int8_t i=0; i<size_array; i++) {
    if ((*(hsv+i)).v==0) {
      *(lit_array+i) = false;
    }
    if((*(hsv+i)).v>0) {
      *(lit_array+i) = true;
    }
  }
}

uint8_t findNumLit(CHSV *hsv,int8_t size_array, bool *lit_array) { //TESTED
  uint8_t numlit=0;
  findLit(hsv,size_array,lit_array);
  for (int8_t i=0; i<size_array; i++) {
    if (*(lit_array+i)==true) {
      numlit++;
    }
  }
  return numlit;
}

bool queryItsLit(CHSV *hsv, int8_t size_array, bool *lit_array) {
  bool itsLit=true;
  findLit(hsv,size_array,lit_array);
  for(int8_t i=0; i<size_array; i++) {
    if (*(lit_array+i)==false) {
      itsLit=false;
    }
  }
  return itsLit;
}

bool queryItsDark(CHSV *hsv, int8_t size_array, bool *lit_array) {
  bool itsDark=true;
  findLit(hsv,size_array,lit_array);
  for(int8_t i=0; i<size_array; i++) {
    if (*(lit_array+i)==true) {
      itsDark=false;
    }
  }
  return itsDark;
}
