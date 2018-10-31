#ifndef PixelRing_h
#define PixelRing_h
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
class PixelRing

{
public:
  PixelRing(int pin, int pixelCount);
  PixelRing();

  void setAnimation(int animationCode);
  void update();
  void start();

  uint8_t getRed(uint32_t col);
  uint8_t getGreen(uint32_t col);
  uint8_t getBlue(uint32_t col);

  enum ColorModes
  {
    RAINBOW,
    JUMP
  };

private:
  uint32_t getNextRainbowColor();
  uint32_t getNextRainbowColor(bool faded, int FadeLevel);
  uint32_t getColorFaded(uint32_t color, float fadeLevel);
  void circle();
};

#endif