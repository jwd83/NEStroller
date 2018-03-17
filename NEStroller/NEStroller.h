/*
  NEStroller
  A simple NES controller interface for the Arduino
  Jared De Blander
  https://github.com/jared0x90
*/

#ifndef NESTROLLER_LIB
#define NESTROLLER_LIB

#include "Arduino.h"

#define NES_BUTTON_UP         3
#define NES_BUTTON_DOWN       2
#define NES_BUTTON_LEFT       1
#define NES_BUTTON_RIGHT      0
#define NES_BUTTON_SELECT     5
#define NES_BUTTON_START      4
#define NES_BUTTON_A          7
#define NES_BUTTON_B          6

class NEStroller {
  public:
    NEStroller();
    void begin(int pinClock, int pinLatch, int pinDataIn);
    void updateButtons();
    bool getButtonPressed(int button_requested);
    byte getButtons();

  private:
    byte _button_states;
    int _pin_clock;
    int _pin_latch;
    int _pin_data_in;
};

#endif
