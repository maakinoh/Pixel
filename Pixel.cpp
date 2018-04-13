#include "Pixel.h"
#include "utils/Color.hpp"
#include "utils/animation/Animation.hpp"
#include <Adafruit_NeoPixel.h>

using namespace animat;
using namespace pixelcolor;

Animation anim;
Color col;

Adafruit_NeoPixel strip;

int animationCount = 0;
int wait = 40;
int animationMode;
int pixels;

bool clearingAfterAnimation = true;

bool clearing;



void on(int pixel, uint32_t color);
void off(int pixel);
void show();



int red = 255;
int green = 0;
int blue = 0;

/*
 * 0 = RED
 * 1 = Yellow
 * 2 = Green
 * 3 = Cyan
 * 4 = Blue
 * 5 = Magentas
 */
int fadeTo;

uint32_t clear = strip.Color(0,0,0,0);

Color::Colors activeColor = Color::Colors::RAINBOW;

Pixel::Pixel(){
    //color* = new Color;
}

Pixel::Pixel(int pin,int pixelCount) {
    //color* = new Color;
    strip = Adafruit_NeoPixel(pixelCount, pin, NEO_GRBW + NEO_KHZ800);
    col = Color();
    anim = CircleAnimation();
    pixels = pixelCount;
}

void Pixel::start(){
    strip.begin();
    strip.setBrightness(20);
    strip.show();
}

void Pixel::setClearingAfterAnimation(bool value){
    clearingAfterAnimation = value;
}


void Pixel::setColor(Color::Colors color){
    activeColor = color;
}

void Pixel::setAnimation(int animationCode){
    animationMode = animationCode;
    animationCount = 0;
}

void Pixel::setTimeOut(int value){
    wait = value;
}
void Pixel::update(){
    switch (animationMode) {
    case 1:
        circle();
        break;
    case 2:
        halfCircleCloseDown();
        break;
    case 3:
        halfCircleCloseUp();
        break;
    case 4:
        halfCircleSpinRight();
        break;
    case 5:
        halfCircleSpinLeft();
        break;
    }
}
void Pixel::halfCircleSpinLeft(){
    if (animationCount>(pixels/2)) {
        animationCount = 0;
        if(clearingAfterAnimation){
            if (!clearing) {
                clearing = true;
            } else {
                clearing = false;
            }
        }
    }
    if (clearing) {
        off((pixels/2)-animationCount);
        off(animationCount);
    } else {
        on((pixels/2)-animationCount,getNextColor());
        on(animationCount,getNextColor());
    }
    show();
    delay(wait);
    animationCount++;
}

void Pixel::halfCircleSpinRight(){
    if (animationCount>(pixels/2)) {
        animationCount = 0;
        if(clearingAfterAnimation){
            if (!clearing) {
                clearing = true;
            } else {
                clearing = false;
            }
        }
    }
    if (clearing) {
        off(animationCount);
        off((pixels/2)+animationCount);
    } else {
        on(animationCount,getNextColor());
        on((pixels/2)+animationCount,getNextColor());
    }
    show();
    delay(wait);
    animationCount++;
}


void Pixel::halfCircleCloseUp(){
    if (animationCount>(pixels/2)) {
        animationCount = 0;
        if (clearingAfterAnimation) {
            if (!clearing) {
                clearing = true;
            } else {
                clearing = false;
            }
        }
    }
    if (clearing) {
        off((pixels/2)-animationCount);
        off((pixels/2)+animationCount);
    } else {
        on((pixels/2)-animationCount,getNextColor());
        on((pixels/2)+animationCount,getNextColor());
    }
    delay(wait);
    show();
    animationCount++;
}



void Pixel::halfCircleCloseDown(){
    if (animationCount>(pixels/2)) {
        animationCount = 0;
        if (clearingAfterAnimation) {
            if (!clearing) {
                clearing = true;
            } else {
                clearing = false;
            }
        }
    }
    if (clearing) {
        off(animationCount);
        off(pixels-animationCount);
    } else {
        on(animationCount,getNextColor());
        on(pixels-animationCount,getNextColor());
    }
    show();
    delay(wait);
    animationCount++;
}

void Pixel::circle(){
    anim.animate(strip,animationCount,col);
    animationCount++;
}


void Pixel::on(int pixel, uint32_t color){
    strip.setPixelColor(pixel,color);
}

void Pixel::off(int pixel){
    strip.setPixelColor(pixel,clear);
}

void Pixel::show(){
    strip.show();
}


uint32_t Pixel::getNextColor(){
    //col.getNextColor();
}
