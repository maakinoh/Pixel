#ifndef Color_h
#define Color_h
#include <Adafruit_NeoPixel.h>
namespace pixelcolor{

class Color {
public:
    Color();
    ~Color();
    enum Colors {
        RED,
        BLUE,
        GREEN,
        YELLOW,
        ORANGE,
        CYAN,
        MAGENTA,
        RAINBOW};
        static uint32_t getColor(Adafruit_NeoPixel strip, Colors color);
        uint32_t getNextColor();
};
}

#endif
