void Sequence1() {
  bool clockways = random8(0,2);

  calibrating();
  
  foldIn(phringLeft,phringRight,pringLeft,pringRight,ringsize,clockways,plit_hringLeft,plit_hringRight,75);
  clockways=!clockways;
  fillRingRainbow(phringLeft,phringRight,pringLeft,pringRight,ringsize,random8(0,12),random8(),14);
//  randomBlinkCurrentHue(phringLeft,phringRight,pringLeft,pringRight,ringsize,12,plit_hringLeft,plit_hringRight,75);
  rotateRing(phringLeft,phringRight,pringLeft,pringRight,ringsize, clockways, ringsize*random8(1,3) + random8(0,6),2,75);
  foldIn(phringLeft,phringRight,pringLeft,pringRight,ringsize,clockways,plit_hringLeft,plit_hringRight,75);

  
  
  
}
