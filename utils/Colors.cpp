#include "utils/Colors.hpp"
#include <Adafruit_NeoPixel.h>

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
