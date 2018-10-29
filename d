#include <PixelRing.h>

#define PIN 6
#define PIN_COUNT 16

PixelRing pixel;

void setup(){
pixel = PixelRing(PIN, PIN_COUNT);

pixel.start();

   
}

void loop() {

   pixel.update();
}