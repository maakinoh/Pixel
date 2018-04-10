## Pixels

#### First Steps
A small Arduino Libary for NeoPixel Rings.

To Start after the installation of the Library
you must include the Pixel.h Header, and Create a Pixel Object

In the setup Method you must initialize the Pixel object with the Datapin on your Arduino (PIN), and the Count of NeoPixels on your NeoPixel Ring.

In The loop Method, the function update() in Pixel must be called.

```c++
#include <Pixel.h>
#define PIN 6
#define PIN_COUNT 16

Pixel pixel;

void setup(){
    pixel = Pixel(PIN, PIN_COUNT);
    pixel.start();
}

void loop() {
    pixel.update();
}

```
---
#### Change Animation

To Change the Animation yo need to call

```c++
pixel.setAnimation(1);
```

The Number is the Code for the animationCode

---
#### Animation Codes

TODO Animations code
