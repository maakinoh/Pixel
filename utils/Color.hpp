#ifndef Color_h
#define Color_h

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
};

#endif
