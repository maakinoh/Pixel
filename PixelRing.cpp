#include "PixelRing.h"

#include <Adafruit_NeoPixel.h>

#include <Arduino.h>

Adafruit_NeoPixel strip;

int pixels;

int animationCount;

// The Identifier for the animation
// 0 = Rainbow
int animationMode = 0;

int red = 255;
int green = 0;
int blue = 0;

int fadeTo = 0;

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
    strip.setPixelColor(animationCount % pixels, getNextRainbowColor());
    strip.setPixelColor((animationCount - 1) % pixels, getActualColorFaded(0.93));
    strip.setPixelColor((animationCount - 2) % pixels, getActualColorFaded(0.95));
    strip.show();
    delay(100);
    strip.setPixelColor(animationCount % pixels, strip.Color(0, 0, 0, 0));
    strip.setPixelColor((animationCount - 1) % pixels, strip.Color(0, 0, 0, 0));
    strip.setPixelColor((animationCount - 2) % pixels, strip.Color(0, 0, 0, 0));
    strip.show();
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

// This function returns the actual color with a fading effect
// The effect intensity is controlled by the passed fadeLevel as an int.
uint32_t PixelRing::getActualColorFaded(float fadeLevel)
{

    int fadedRed = red - (red * fadeLevel);
    int fadedGreen = green - (green * fadeLevel);
    int fadedBlue = blue - (blue * fadeLevel);

    return strip.Color(fadedRed, fadedGreen, fadedBlue, 0);
}

uint32_t PixelRing::getNextRainbowColor(bool faded, int fadeLevel)
{
}

uint32_t PixelRing::getNextRainbowColor()
{

    switch (fadeTo)
    {
    //Fading to Yellow
    case 0:
        if (green < 255)
        {
            green++;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 1;
            return strip.Color(red, green, blue, 0);
        }
        break;
    //Fading to Green
    case 1:
        if (red > 0)
        {
            red--;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 2;
            return strip.Color(red, green, blue, 0);
        }
        break;
    //Fading To Cyan
    case 2:
        if (blue < 255)
        {
            blue++;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 3;
            return strip.Color(red, green, blue, 0);
        }
        break;
    //Fade to Blue
    case 3:
        if (green > 0)
        {
            green--;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 4;
            return strip.Color(red, green, blue, 0);
        }
        break;
    //Fade To Magenta
    case 4:
        if (red < 255)
        {
            red++;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 5;
            return strip.Color(red, green, blue, 0);
        }
        break;
    //Fade Back to Red
    case 5:
        if (blue > 0)
        {
            blue--;
            return strip.Color(red, green, blue, 0);
        }
        else
        {
            fadeTo = 0;
            return strip.Color(red, green, blue, 0);
        }
        break;
    }
}

void PixelRing::update()
{

    circle();
}