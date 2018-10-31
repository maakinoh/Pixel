#include "PixelRing.h"

Adafruit_NeoPixel strip;

int pixels;

int animationCount;

// The Identifier for the animation
// 0 = Rainbow
int animationMode = 0;

int red = 255;
int green = 0;
int blue = 0;

int colorState = 0;

PixelRing::PixelRing()
{
}

PixelRing::PixelRing(int pin, int pixelCount)
{
    strip = Adafruit_NeoPixel(pixelCount, pin, NEO_GRBW + NEO_KHZ800);
    pixels = pixelCount;
}

void PixelRing::start()
{
    strip.begin();
    strip.setBrightness(20);
    strip.show();
    animationCount = 0;
}

void PixelRing::circle()
{

    uint32_t col = getNextRainbowColor();

    strip.setPixelColor(animationCount % pixels, col);
    strip.setPixelColor((animationCount - 1) % pixels, getColorFaded(col, 0.8));
    strip.setPixelColor((animationCount - 2) % pixels, getColorFaded(col, 0.8));
    strip.show();
    delay(200);
    strip.setPixelColor(animationCount % pixels, strip.Color(0, 0, 0, 0));
    strip.setPixelColor((animationCount - 1) % pixels, strip.Color(0, 0, 0, 0));
    strip.setPixelColor((animationCount - 2) % pixels, strip.Color(0, 0, 0, 0));

    animationCount++;

    if (animationCount >= pixels)
    {
        strip.setPixelColor(animationCount, strip.Color(0, 0, 0, 0));
        animationCount = 0;
    }
}

// This Function returns the nextToShowncolor
// and count
void getNextColor()
{
    switch (animationMode)
    {
    case 0:
        break;
    }
}

uint8_t PixelRing::getBlue(uint32_t col)
{
    return (uint8_t)(col);
}

uint8_t PixelRing::getGreen(uint32_t col)
{
    return (uint8_t)(col >> 8);
}

// Calculate the red value of the passed color.
//
// Parameter:
//      col as uint32_t  The colorvalue to calculate the red value.
uint8_t PixelRing::getRed(uint32_t col)
{
    return (uint8_t)(col >> 16);
}

// This function returns the actual color with a fading effect
// The effect intensity is controlled by the passed fadeLevel as an int.
uint32_t PixelRing::getColorFaded(uint32_t color, float fadeLevel)
{
    uint8_t fadedRed, fadedGreen, fadedBlue;

    fadedRed = getRed(color);
    fadedRed = fadedRed - (fadedRed * fadeLevel);

    fadedGreen = getGreen(color);
    fadedGreen = fadedGreen - (fadedGreen * fadeLevel);

    fadedBlue = getBlue(color);
    fadedBlue = fadedBlue - (fadedBlue * fadeLevel);

    return strip.Color(fadedRed, fadedGreen, fadedBlue, 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

uint32_t PixelRing::getNextRainbowColor()
{
    colorState++;
    return Wheel(colorState);
}

void PixelRing::update()
{

    circle();
}