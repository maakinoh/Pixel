#ifndef Pixel_h
#define Pixel_h
#include <Adafruit_NeoPixel.h>
#include "utils/Colors.hpp"
// the #include statment and code go here...


class Pixel
{

public:
    Pixel(int pin, int pixelCount);
    Pixel();
    void setAnimation(int animationCode);
    void update();
    void show();
    void start();
    void setColor(Color::Colors color);
    void setClearingAfterAnimation(bool value);
    void setTimeOut(int value);
private:
    //uint32_t getNextColor();
    Adafruit_NeoPixel strip;
    void circle();
    void halfCircleCloseDown();
    void halfCircleCloseUp();
    void on(int pixel, uint32_t color);
    void off(int pixel);
    uint32_t getNextColor();

};
#endif
