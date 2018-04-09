#ifndef Colors_h
#define Colors_h
class Color{
public:
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

};

#endif
