#ifndef BLINKINGLED_H
#define BLINKINGLED_H
#include <Arduino.h>

class BlinkingLED
{
public:
    const int LEDPin1 = 12;
    const int LEDPin2 = 11;
    int iterator = 0;

    void setup()
    {
        pinMode(LEDPin1, OUTPUT);
        pinMode(LEDPin2, OUTPUT);
        digitalWrite(LEDPin2, HIGH);
        delay(500);
    }

    void loop()
    {
        if (iterator < 10) {
            digitalWrite(LEDPin1, HIGH);
            digitalWrite(LEDPin2, LOW);
            delay(500);

            digitalWrite(LEDPin1, LOW);
            digitalWrite(LEDPin2, HIGH);
            delay(500);

            iterator++;
        }
    }
};

#endif