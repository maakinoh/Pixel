#include <Pixel.h>
#include <Adafruit_NeoPixel.h>
#include <Animation.h>


Adafruit_NeoPixel strip;
Pixel::Pixel(int pin,int pixelCount) {
    strip = Adafruit_NeoPixel(PIN_COUNT, PIN, NEO_GRB + NEO_KHZ800);
}


void Pixel::setAnimation(){

}


void Pixel::update(){


}
