#include "Pixel.h"
#include "Adafruit_NeoPixel.h"


Adafruit_NeoPixel strip;
int animationCount;
int animationMode;

Pixel::Pixel(int pin,int pixelCount) {
    strip = Adafruit_NeoPixel(PIN_COUNT, PIN, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.setBrightness(20);
    strip.show();
}



void Pixel::setAnimation(int animationCode){

}


void Pixel::update(){
  switch(animationMode){
    case 1:
      break;
  }

}


void on(int pixel, uint32_t color ){
  strip.setPixelColor(pixel,color);
}
