#ifndef Pixel_h_
#define Pixel_h_
#include <Adafruit_NeoPixel.h>
// the #include statment and code go here...

class Pixel{
public:
    Pixel(int pin, int pixelCount);
    void setAnimation(int animationCode);
    void update();
};

#endif
