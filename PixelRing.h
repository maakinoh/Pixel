#ifndef PixelRing_h
#define PixelRing_h
#include <Adafruit_NeoPixel.h>
class PixelRing

{
public:
  PixelRing(int pin, int pixelCount);
  PixelRing();
  void setAnimation(int animationCode);
  void update();
  void start();
  enum ColorModes
  {
    RAINBOW,
    JUMP
  };

private:
  uint32_t getNextRainbowColor();
  uint32_t getNextRainbowColor(bool faded, int FadeLevel);
  uint32_t getActualColorFaded(float fadeLevel);
  void circle();
};

#endif