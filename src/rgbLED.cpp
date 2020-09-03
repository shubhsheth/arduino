#include <Arduino.h>

#ifndef RGB_H
#define RGB_H
class RGB
{
public:
    const int redLedPin = 13;
    const int greenLedPin = 12;
    const int blueLedPin = 11;
    const int sensorPin = 0;

    int iterator = 0;
    int sensorValue = 0;

    void setup()
    {
        pinMode(redLedPin, OUTPUT);
        pinMode(greenLedPin, OUTPUT);
        pinMode(blueLedPin, OUTPUT);

        Serial.begin(9600);
    }

    void loop()
    {
        sensorValue = analogRead(sensorPin);

        if (iterator >= 768)
        {
            iterator = 0;
        }
        showSpectrum(iterator);
        delay(sensorValue);

        iterator++;
    }

    void showSpectrum(int color)
    {
        int redIntensity, greenIntensity, blueIntensity;
        if (color <= 255)
        {
            redIntensity = 255 - color;
            greenIntensity = color;
            blueIntensity = 0;
        }
        else if (color <= 511)
        {
            redIntensity = 0;
            greenIntensity = 255 - (color - 256);
            blueIntensity = color - 256;
        }
        else
        {
            redIntensity = color - 512;
            greenIntensity = 0;
            blueIntensity = 255 - (color - 512);
        }

        analogWrite(redLedPin, redIntensity);
        analogWrite(greenLedPin, greenIntensity);
        analogWrite(blueLedPin, blueIntensity);

        // Serial.print("Red:");
        // Serial.print(redIntensity);
        // Serial.print(" Green:");
        // Serial.print(greenIntensity);
        // Serial.print(" Blue:");
        // Serial.println(blueIntensity);

    }
};

#endif