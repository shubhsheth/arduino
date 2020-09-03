#include "blinkingLED.cpp"
#include "potentiometer.cpp"
#include "rgbLED.cpp"

BlinkingLED LED;
Pot Pot;
RGB RGB;

int btn1Pin = 2;
int btn2Pin = 3;
int ledPin = 13;

void setup()
{
	// RGB.setup();
	pinMode(btn1Pin, INPUT);
	pinMode(btn2Pin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop()
{
	int btn1State, btn2State;

	btn1State = digitalRead(btn1Pin);
	btn2State = digitalRead(btn2Pin);

	if ((btn1State == LOW || btn2State == LOW) && !(btn1State == LOW && btn2State == LOW))
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
}