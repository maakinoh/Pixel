#ifndef Color_h
#define Color_h
#include <Adafruit_NeoPixel.h>
#include "utils/Colors.h"
namespace pixelcolor{

class Color {
public:
  Color();
  ~Color();
  static uint32_t getColor(Adafruit_NeoPixel strip, colors::Colors color);
  uint32_t getNextColor();
};
}

#endif
