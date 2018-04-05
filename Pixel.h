#ifndef Pixel_h
#define Pixel_h
#include <Adafruit_NeoPixel.h>
// the #include statment and code go here...

class Pixel{
public:
    Pixel(int pin, int pixelCount);
    void setAnimation();
    void update();

};

#endif
