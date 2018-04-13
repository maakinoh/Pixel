#include <Adafruit_NeoPixel.h>
#include "utils/Color.hpp"
#include "utils/animation/Animation.h"


using namespace animat;

void Animation::on(int pixel, uint32_t color,Adafruit_NeoPixel strip)
{
    strip.setPixelColor(pixel,color);
}
void Animation::off(int pixel,Adafruit_NeoPixel strip)
{
    strip.setPixelColor(pixel,clear);
}
