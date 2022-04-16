# jonas-arduino-librarys
Some Botched Arduino Librarys that don't make sense

# Include
To include the librarys into your Arduino Project just copy this into your platform.io file
```
>lib_deps = 
    https://github.com/JonasHellrigl/jonas-blink-library
```
You also need to write the following at the start of your code, depending on which library you want to use

Blink Library: ```#include <Blink.h>```

Fade Library: ```#include <Fade.h>```

Delay Library: ```#include <Delay.h>```

Debounce Button Library: ```#include <Debounce.h>```


# How to use Blink.h
The Library contains 2 types of blinking
## 1) Blinking Infinite
This type of blinking, has a constant interval, that it blinks in.
- ### Constructor: 
```
Blink LED = Blink(int Pin, unsigned long Interval);
```
- ### Usage:
```
LED.BlinkInfinite();
```
## 2) Blinking an amount of times
This type of blinking, has a given amount of blinking and a given HIGH and LOW time
- ### Constructor: 
```
Blink LED = Blink(int pin, unsigned long durationHIGH, unsigned long durationLOW, int quantityBlink)
```
- ### Usage:
```
LED.BlinkQuantity();
```
