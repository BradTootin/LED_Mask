void findLit() {
  for (int8_t i=0; i<ringsize; i++) {
    if ((*(phringLeft+i)).v==0) {
      *(plit_hringLeft+i) = false;
    }
    if((*(phringLeft+i)).v>0) {
      *(plit_hringLeft+i) = true;
    }
    if ((*(phringRight+i)).v==0) {
      *(plit_hringRight+i) = false;
    }
    if ((*(phringRight+i)).v > 0) {
      *(plit_hringRight+i) = true;
    }
    if ((*(poringLeft1+i)).v==0) {
      *(plit_oringLeft1+i) = false;
    }
    if((*(poringLeft2+i)).v>0) {
      *(plit_oringLeft2+i) = true;
    }
    if ((*(poringRight1+i)).v==0) {
      *(plit_oringRight1+i) = false;
    }
    if((*(poringRight2+i)).v>0) {
      *(plit_oringRight2+i) = true;
    }
  }
}

int8_t findNumLit(CHSV *hsv) {
  int8_t valreturn=0;
  uint8_t value_read;
  findLit();
  for (int8_t i=0; i<ringsize; i++) {
    value_read = (*(hsv+i)).value;
    if (value_read>0) {
      valreturn +=1;

    }
  }
  int8_t numlit=valreturn;
  return numlit;
}


void createUnlitList(CHSV *hsv, int8_t *unlitList) { // populates a list of unlit positions
  int8_t numLit = findNumLit(hsv);
  int8_t count = 0; // count for the index of the unlit array
//  int8_t unlitList[ringsize];
  for(int i=0; i<ringsize;i++) {
    *(unlitList +i) = 0; // predefine as zero
  }
  for(int i=0; i<ringsize; i++) { 
    if ((*(hsv+i)).v==0) { // 
      *(unlitList+count)= i;
      count++;
    }
  }
}

bool queryItsLit(CHSV *hsv) { // TESTED
  bool itsLit=true;
//  findLit();
  for(int8_t i=0; i<ringsize; i++) {
    if ((*(hsv+i)).v == 0) {
      itsLit=false;
      return itsLit;
    }
  }
  return itsLit;
}

bool queryItsDark(CHSV *hsv) { // TESTED
  bool itsDark=true;
//  findLit();
  for(int8_t i=0; i<ringsize; i++) {
    if ((*(hsv+i)).v>0) {
      itsDark=false;
      return itsDark;
    }
  }
  return itsDark;
}
