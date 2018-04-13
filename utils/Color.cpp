#include "utils/Color.hpp"
#include <Adafruit_NeoPixel.h>

Color::Colors activeColor = Color::Colors::RAINBOW;
using namespace pixelcolor;

Color::Color(){

}

Color::~Color(){


}

int red = 255;
int green = 0;
int blue = 0;

uint32_t Color::getColor(Adafruit_NeoPixel strip, Color::Colors color){
    switch (color)
    {
    case RED:
        return strip.Color(255,0,0);
    case BLUE:
        return strip.Color(0,0,255);
    case GREEN:
        return strip.Color(0,255,0);
    case YELLOW:
        return strip.Color(255,255,0);
    case ORANGE:
        return strip.Color(255,127,0);
    case CYAN:
        return strip.Color(0,255,255);
    case MAGENTA:
        return strip.Color(255,0,255);
    default:
        break;
    }
}

Color::getNextColor(){
    if (activeColor != Color::Colors::RAINBOW) {
        return Color::getColor(strip, activeColor);
    }
  switch(fadeTo){
    //Fading to Yellow
    case 0:
    if (green<255) {
      green++;
      return strip.Color(red, green, blue,0);
    } else {
      fadeTo = 1;
      return strip.Color(red, green, blue,0);
    }
    break;
    //Fading to Green
    case 1:
    if (red>0) {
      red--;
      return strip.Color(red, green, blue,0);
    } else{
      fadeTo = 2;
      return strip.Color(red, green, blue,0);
    }
    break;
    //Fading To Cyan
    case 2:
    if (blue<255) {
      blue++;
      return strip.Color(red, green, blue,0);
    } else {
      fadeTo = 3;
      return strip.Color(red, green, blue,0);
    }
    break;
    //Fade to Blue
    case 3:
    if (green>0) {
      green--;
      return strip.Color(red, green, blue,0);
    } else {
      fadeTo = 4;
      return strip.Color(red, green, blue,0);
    }
    break;
    //Fade To Magenta
    case 4:
    if (red<255) {
      red++;
      return strip.Color(red, green, blue,0);
    } else {
      fadeTo = 5;
      return strip.Color(red, green, blue,0);
    }
    break;
    //Fade Back to Red
    case 5:
    if (blue>0) {
      blue--;
      return strip.Color(red, green, blue,0);
    } else {
      fadeTo = 0;
      return strip.Color(red, green, blue,0);
    }
    break;
  }
}
