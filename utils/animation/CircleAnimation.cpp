#include "utils/animation/Animation.h"
#include <Adafruit_NeoPixel.h>
#include "utils/Color.h"

using namespace animat;
using namespace pixelcolor;

void CircleAnimation::animate(Adafruit_NeoPixel strip,int animationCount , uint32_t color){

}

void CircleAnimation::animate(Adafruit_NeoPixel strip,int animationCount , Color::Colors color){

    Serial.println("CircleAnima Class");
    if (animationCount>(pixels-2)){
        animationCount = 0;
    }
    on(animationCount,color.getNextColor());
    on(animationCount+1,color.getNextColor());
    on(animationCount+2,color.getNextColor());
    show();
    delay(wait);
    if (clearingAfterAnimation) {
        off(animationCount);
        off(animationCount+1);
        off(animationCount+2);
        show();
    }
}
