#ifndef Animation_h
#define Animation_h
#include <Adafruit_NeoPixel.h>
#include "utils/Color.hpp"

namespace animat{

    class Animation{
    public:
        void animate(Adafruit_NeoPixel strip,int animationCount , uint32_t color);
        void animate(Adafruit_NeoPixel strip,int animationCount , pixelcolor::Color::Colors color);
        void animate(Adafruit_NeoPixel strip,int animationCount , pixelcolor::Color color);
    protected:
        void on(int pixel, uint32_t color,Adafruit_NeoPixel strip);
        void off(int pixel,Adafruit_NeoPixel strip);

    };

    class CircleAnimation : public Animation {
    public:
        void animate(Adafruit_NeoPixel strip,int animationCount , uint32_t color);
        void animate(Adafruit_NeoPixel strip,int animationCount , pixelcolor::Color::Colors color);
        void animate(Adafruit_NeoPixel strip,int animationCount , pixelcolor::Color color);
    };
}
#endif
