/*
  NEStroller
  A simple NES controller interface for the Arduino
  Jared De Blander
  https://github.com/jared0x90
*/

#include "Arduino.h"
#include "NEStroller.h"

#define TIMING_DELAY    10

NEStroller::NEStroller() {

}

void NEStroller::begin(int pinClock, int pinLatch, int pinDataIn) {
  _pin_clock = pinClock;
  _pin_latch = pinLatch;
  _pin_data_in = pinDataIn;


  pinMode(_pin_clock , OUTPUT);
  pinMode(_pin_latch , OUTPUT);
  pinMode(_pin_data_in , INPUT);
}

void NEStroller::updateButtons() {
  _button_states = 0;

  // default all pins to low
  digitalWrite(_pin_latch, LOW);
  digitalWrite(_pin_clock, LOW);

  // instruct the controller to latch (read the buttons states and store them)
  digitalWrite(_pin_latch, HIGH);

  // wait for the data to be ready
  delayMicroseconds(TIMING_DELAY);
  
  // release the latch to begin transferring data. the first state will be immediately 
  // available on the data in / strobe line.
  digitalWrite(_pin_latch, LOW);

  // wait for the data to be ready
  delayMicroseconds(TIMING_DELAY);

  // Store if the A button is pressed (first bit out of the shift register)
  _button_states = digitalRead(_pin_data_in);

  // loop through the remaining 7 buttons
  for (int buttons = 1; buttons <= 7; buttons++) {
    digitalWrite(_pin_clock, HIGH);
    delayMicroseconds(TIMING_DELAY);
    _button_states = _button_states << 1;
    _button_states = _button_states + digitalRead(_pin_data_in) ;
    delayMicroseconds(TIMING_DELAY);
    digitalWrite(_pin_clock, LOW);
  }
}

bool NEStroller::getButtonPressed(int button_requested) {
  return bitRead(_button_states, button_requested) == 0;

}

byte NEStroller::getButtons() {
  return _button_states;
}
