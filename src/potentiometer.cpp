#include <Arduino.h>

#ifndef POT_H
#define POT_H
class Pot
{
public:
    int sensorPin = 0;
    int ledYPin = 13;
    int ledGPin = 12;

    void setup()
    {
        pinMode(ledYPin, OUTPUT);
        pinMode(ledGPin, OUTPUT);
    }

    void loop()
    {
        int sensorValue;
        sensorValue = analogRead(sensorPin);

        digitalWrite(ledYPin, HIGH);
        digitalWrite(ledGPin, LOW);
        delay(sensorValue);

        digitalWrite(ledYPin, LOW);
        digitalWrite(ledGPin, HIGH);
        delay(sensorValue);
    }
};
#endif