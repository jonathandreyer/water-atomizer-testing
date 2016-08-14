/**
 * Tester Grove water atomization v1.0
 * Turns on an humidity generator when button is pressed.
 */

#include "Arduino.h"

#define PIN_BUTTON 2
#define PIN_LED 13
#define PIN_HUMIDITY 6


int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonSate = 0;
int humidityState = 0;

void setup()
{
  // Initialize modules
  Serial.begin(9600);

  // initialize the LED pin as an output:
  pinMode(PIN_LED, OUTPUT);
  // initialize the water atomization pin as an output:
  pinMode(PIN_HUMIDITY, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(PIN_BUTTON, INPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(PIN_BUTTON);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if ((buttonState == true) && (lastButtonSate == false)) {
    humidityState = !humidityState;

    if (humidityState == true) {
        // enable humidity & LED:
        digitalWrite(PIN_LED, HIGH);
        digitalWrite(PIN_HUMIDITY, HIGH);
        Serial.print("Enable ");
    }
    else {
        // disable humidity & LED:
        digitalWrite(PIN_LED, LOW);
        digitalWrite(PIN_HUMIDITY, LOW);
        Serial.print("Disable ");
    }
    Serial.println("atomization & LED");
  }

  lastButtonSate = buttonState;

  delay(20);
}
