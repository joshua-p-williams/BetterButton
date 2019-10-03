#include "BetterButton.h"

// Use pin 2 as our button
BetterButton myButton(2);

void setup()
{
    Serial.begin(9600);
    myButton.begin();
}

void loop()
{
    switch (myButton.input())
    {
    case (BUTTON_LONG_PRESSED):
        Serial.println(F("Long Pressed"));
        break;
    case (BUTTON_DOUBLE_CLICKED):
        Serial.println(F("Double Clicked"));
        break;
    case (BUTTON_CLICKED):
        Serial.println(F("Clicked"));
        break;
    default:
        break;
    }
}
