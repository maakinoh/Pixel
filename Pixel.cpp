#include <Pixel.h>
#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel strip;
int animationCount = 0;
int wait = 50;
int animationMode;
int pixels;

uint32_t getNextColor();
//void circle();
void on(int pixel, uint32_t color);
void off(int pixel);
void show();
uint32_t getColor(Pixel::Colors color);

int red = 255;
int green = 0;
int blue = 0;

/*
 * 0 = RED
 * 1 = Yellow
 * 2 = Green
 * 3 = Cyan
 * 4 = Blue
 * 5 = Magentas
 */
int fadeTo;
uint32_t clear = strip.Color(0,0,0);

Pixel::Pixel(){

}


void Pixel::start(){
    strip.begin();
    strip.setBrightness(20);
    strip.show();
}

Pixel::Pixel(int pin,int pixelCount) {
    strip = Adafruit_NeoPixel(pixelCount, pin, NEO_GRB + NEO_KHZ800);
    pixels = pixelCount;
}





void Pixel::setAnimation(int animationCode){
    animationMode = animationCode;
}


void Pixel::update(){
  switch(animationMode){
    case 1:
        circle();
      break;
  }

}

void Pixel::circle(){
    on(animationCount,getNextColor());
    on(animationCount+1,getNextColor());
    on(animationCount+2,getNextColor());
    show();
    delay(wait);
    off(animationCount);
    off(animationCount+1);
    off(animationCount+2);
    show();
    animationCount++;
    if (animationCount>=pixels){
        animationCount = 0;
    }
}


void Pixel::on(int pixel, uint32_t color){
  strip.setPixelColor(pixel,color);
}

void Pixel::off(int pixel){
    strip.setPixelColor(pixel,clear);
}

void Pixel::show(){
    strip.show();
}


uint32_t getNextColor(){
  switch(fadeTo){
    //Fading to Yellow
    case 0:
    if (green<255) {
      green++;
      return strip.Color(red, green, blue);
    } else {
      fadeTo = 1;
      return strip.Color(red, green, blue);
    }
    break;

    //Fading to Green
    case 1:
    if (red>0) {
      red--;
      return strip.Color(red, green, blue);
    } else{
      fadeTo = 2;
      return strip.Color(red, green, blue);
    }
    break;
    //Fading To Cyan
    case 2:
    if (blue<255) {
      blue++;
      return strip.Color(red, green, blue);
    } else {
      fadeTo = 3;
      return strip.Color(red, green, blue);
    }
    break;
    //Fade to Blue
    case 3:
    if (green>0) {
      green--;
      return strip.Color(red, green, blue);
    } else {
      fadeTo = 4;
      return strip.Color(red, green, blue);
    }
    break;
    //Fade To Magenta
    case 4:
    if (red<255) {
      red++;
      return strip.Color(red, green, blue);
    } else {
      fadeTo = 5;
      return strip.Color(red, green, blue);
    }
    break;
    //Fade Back to Red
    case 5:
    if (blue>0) {
      blue--;
      return strip.Color(red, green, blue);
    } else {
      fadeTo = 0;
      return strip.Color(red, green, blue);
    }
    break;
  }
}
