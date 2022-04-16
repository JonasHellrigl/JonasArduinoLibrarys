# jonas-arduino-librarys
Some Botched Arduino Librarys that don't make sense made by an TFO'ler

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
This type of blinking, has a constant interval, that it blinks in

- ### Constructor: 
```
Blink LED = Blink(int Pin, unsigned long Interval);
```
- ### Usage:
```
LED.BlinkInfinite();
```
- ### Other functions:
```
LED.Set_IntervalInfinite(unsigned long interval);
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
- ### Other functions:
```
LED.Set_QuantityBlink(int quantityBlink);
```

# How to use Fade.h
Fade.h fades a LED in a given Interval.

It starts at LOW and slowly increases the brightness by +15.

When the Brightness is at 255, the Brightness decreases by -15;

- ### Constructor: (it must be a PWM Pin)
```
Fade LED = Fade(int Pin, unsigned long Interval);
```
- ### Usage:
```
LED.FadeLED();
```
- ### Other functions:
```
LED.Set_Interval(unsigned long Interval);
```

# How to use Delay.h

- ### Constructor:
```
Delay delay1 = Delay(unsigned long interval)
```
- ### Usage:
```
delay1.Use_Delay();
```

# How to use Debounce.h
