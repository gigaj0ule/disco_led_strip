/*

if (myFFT.available()) {  
    float fftAccum   = 0;
    int fftAvg       = 0;  
    int max_bins     = 255;
    int currentColor = 0;
    
    for (int led = (nLEDs - 1); led >= 0; led--) {                
      colorBuffer[led] = colorBuffer[led-1];
    }
    
    for(int bin = 0; bin < max_bins; bin++){
      fftAccum += ((float)255 * myFFT.read(bin) * preamp);
      fftAvg = fftAccum / max_bins; 
    }
    
    int wheelAngle = map(fftAvg, 0, 255, 0, 384);
    currentColor = Wheel(wheelAngle);
       
    colorBuffer[0] = currentColor; 
       
    for(int led = 0; led < nLEDs; led++){
      strip.setPixelColor(led, colorBuffer[led]);    
    }
    
    strip.show();
  }
  
  
  */
  
  
/*if (doFFT){
    
  if (myFFT.available()) {    
 
    // ----------------------------------------------------------------------------- 
   
    // Set passband for Power Spectral Density calculation
    int spectralEnergyLow  = 4;
    int spectralEnergyHigh = 64;
    long spectralIntegrator;

    // Integrate the FFT bins over the passband, square amplitude
    for(int bin = spectralEnergyLow; bin < spectralEnergyHigh; bin++){
      float fftBinByte = 255 * myFFT.read(bin);
      spectralIntegrator += fftBinByte * fftBinByte;
    }  
    
    spectralIntegrator = spectralIntegrator / (spectralEnergyHigh - spectralEnergyLow);

    // Luminance will be the spectralIntegrator byte / 255 (float from 0 to 1)
    lumGlobal = (float)spectralIntegrator / 255;
    lumGlobal = constrain(lumGlobal, 0, 1);
    
    // ----------------------------------------------------------------------------- 

    // Set passband for Color
    spectralEnergyLow  = 4;
    spectralEnergyHigh = 127;
    spectralIntegrator = 0;

    // Integrate the FFT bins over the passband, square amplitude
    for(int bin = spectralEnergyLow; bin < spectralEnergyHigh; bin++){
      float fftBinByte = 384 * myFFT.read(bin);
      spectralIntegrator += fftBinByte; // fftBinByte
    }  
    
    spectralIntegrator = spectralIntegrator // (spectralEnergyHigh - spectralEnergyLow);
    Wheel(spectralIntegrator);
    
    redBuffer[nLEDs/2] = redGlobal;
    grnBuffer[nLEDs/2] = grnGlobal;
    bluBuffer[nLEDs/2] = bluGlobal; 
    //lumBuffer[nLEDs/2] = lumGlobal; 
  }   
  
  // ----------------------------------------------------------------------------- 
  
  for(int led = 0; led < nLEDs; led ++){
         
      int red = (float)lumGlobal * redBuffer[led];
      int grn = (float)lumGlobal * grnBuffer[led];
      int blu = (float)lumGlobal * bluBuffer[led];
  
      strip.setPixelColor(led, red, grn, blu);
    }
    
    int white = (float)lumGlobal * 255;

    strip.setPixelColor(nLEDs/2    , white, white, white);
    strip.setPixelColor(nLEDs/2 + 1, white, white, white);
    strip.setPixelColor(nLEDs/2 - 1, white, white, white);

    strip.setPixelColor(nLEDs/2 + 3, white, white, white);
    strip.setPixelColor(nLEDs/2 - 3, white, white, white);

    strip.setPixelColor(nLEDs/2 + 6, white, white, white);
    strip.setPixelColor(nLEDs/2 - 6, white, white, white);
         
         
    // Roll the FIFO buffer by one step (split down middle)

    for (int led = nLEDs-1; led >= nLEDs/2; led--){      
      redBuffer[led] = redBuffer[led-1];
      grnBuffer[led] = grnBuffer[led-1];
      bluBuffer[led] = bluBuffer[led-1];
      //lumBuffer[led] = lumBuffer[led-1];
      
      int led2 = nLEDs - led;
      
      redBuffer[led2-1] = redBuffer[led2+1];
      grnBuffer[led2-1] = grnBuffer[led2+1];
      bluBuffer[led2-1] = bluBuffer[led2+1];
      //lumBuffer[led2-1] = lumBuffer[led2+1];;
    }
  }
*/
