# BetterButton
Get more use out of a button in Arduino or other embedded projects.  

* Click
* Double Click
* Long Press

Get more use out of a single button.  GPIO's are limited resources on embedded projects, and there is no reason you have should have to throw another button on your project if you can accept more input on a single button.  Extend your projects with clicks, double clicks and long presses, similiar to how a mouse has a click or a double click, or a click and drag, or a smartphone interface can accept gestures.

## Useage

This class will accept a GPIO pin, and will handle debouncing concerns as well as give an elegant way to handle input.  Simply connect a button to ground and a digial IO pin (the example uses digial pin 2).

### Initialize

After including the class in your project;

```cpp
#include "BetterButton.h"
```

Create a BetterButton instance for the GPIO pin designated as the button.

```cpp
BetterButton myButton(2);
```

### Setup

In the setup routine, calling begin will wire the button up with internal pullups (normally high).  When pressing the button will close the circuit to ground (bringing the line low).

```cpp
void setup()
{
	myButton.begin();
}
```

### Main Loop
The class's input() function needs to be embedded in a call within your main loop frequently, with enough opportunity to capture reads every couple hundred milliseconds or so, in order to properly capture user input correctly.  
The input function will return a value greater than zero if there is input that needs to be handled.  You must either handle the input immediately, or store the value upon read for later evaluation.  As soon as input is found and returned in a call to input(), the class will assume it has been handled, and begin watching for additional input.  It's up to your application to either handle immediately upon input availability, or queue for later processing.

```cpp
void loop()
{
	int buttonInput = myButton.input();
	if (buttonInput > 0) 
	{
		// Handle immediately
		handleButtonInput(buttonInput);
		// Or
		// Push onto queue / stack for later processing
		myStack.push(buttonInput);
	}
	
	doOtherStuff();
}
```

### Handling Type Of Click
If you are inly interested in knowing the button was clicked, you need only check for a return value > 0.  However, you can further inspect the return value to determine the specific type of "click" that was made.

* BUTTON_CLICKED
* BUTTON_DOUBLE_CLICKED
* BUTTON_LONG_PRESSED

```cpp
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
```