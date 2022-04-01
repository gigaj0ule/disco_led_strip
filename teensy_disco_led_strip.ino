//#include "LPD8806.h"
//#include <SPI.h>
//#include <Audio.h>
//#include <SD.h>
//#include <Wire.h>
//#include <SerialFlash.h> 

#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define nLEDs  114*25
#define FRAMERATE 30
#define MAX_ANIMATION 4

CRGB leds[nLEDs];
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

int dataPin    = 11;
int clockPin   = 13;

byte current_animation = 0;

//int doFFT = false;

//byte   redBuffer[nLEDs];
//byte   grnBuffer[nLEDs];
//byte   bluBuffer[nLEDs];
//byte  bluGlobal;
//byte  redGlobal;
//byte  grnGlobal;
//analogReference(EXTERNAL);

//AudioInputAnalog      adc1(A0);

//AudioAnalyzeFFT256    myFFT;
//AudioAnalyzePeak      myPeak;

//AudioConnection       patchCord1(adc1, 0, myFFT, 0);
//AudioConnection       patchCord2(adc1, 0, myPeak, 0);

IntervalTimer the_interval;

void setup() {
  the_interval.begin(intervalometer, 2000000);
  
  //AudioMemory(12);
  
  //FastLED.setLeds(nLEDs);
  FastLED.addLeds<LPD8806, RGB>(leds, nLEDs);
  FastLED.setBrightness(255);
  
  //myFFT.windowFunction(AudioWindowHanning256);   // Slow
  //myFFT.windowFunction(AudioWindowBartlett256);  // Fast
  //myFFT.windowFunction(AudioWindowBlackman256);  // Fast
  //myFFT.windowFunction(AudioWindowFlattop256);  // Fast

  //myFFT.averageTogether(8);
  
  /*
  EVERY_N_MILLISECONDS( 20 ) { 
    gHue++; 
  };*/
  
  /*EVERY_N_SECONDS( 1000 ) { 
   if(current_animation < (MAX_ANIMATION + 1)){
      current_animation = current_animation + 1;
   }else{
      current_animation = 0;
   };
  };*/
}



void loop() { 
  switch(current_animation){
    case 0:
      bpm(60);
      break;
    case 1:
      rainbow();
      break;
    case 2:
      confetti();
      break;
    case 3:
      //rainbowithGlitter();
      juggle();
      break;
    case 4:
      sinelon();
      break;
  }

  FastLED.show();
  FastLED.delay(1000/FRAMERATE);
}

void blank(){
  fill_solid( leds, nLEDs, CRGB(50,0,200));
}

void confetti(){
  // random colored speckles that blink in and fade smoothly
  //CRGB(50,0,200);
  fadeToBlackBy(leds, nLEDs, 100);
  int pos = random16(nLEDs);
  leds[pos] += CHSV( gHue + random8(64), 0, 255);
}

void bpm(uint8_t bpm){
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = bpm;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < nLEDs; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void sinelon(){
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, nLEDs, 20);
  int pos = beatsin16(13,15,nLEDs);
  leds[pos] += CHSV( gHue, 255, 192);
}


//----------------------------------

void intervalometer(){
   if(current_animation < (MAX_ANIMATION + 1)){
      current_animation = current_animation + 1;
   }else{
      current_animation = 0;
   };
}


void rainbow() {
  fill_rainbow( leds, nLEDs, 0, 7);
}


void rainbowWithGlitter(){
  rainbow();
  addGlitter(100);
}

void addGlitter( fract8 chanceOfGlitter){
  if( random8() < chanceOfGlitter) {
    leds[ random16(nLEDs) ] += CRGB::White;
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, nLEDs, 20);
  byte dothue = 0;
  for( int i = 0; i < 128; i++) {
    leds[beatsin16(i+64,0,nLEDs)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

