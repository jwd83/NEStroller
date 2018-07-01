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

#define SNES_BUTTON_B           15
#define SNES_BUTTON_Y           14
#define SNES_BUTTON_SELECT      13
#define SNES_BUTTON_START       12
#define SNES_BUTTON_UP          11
#define SNES_BUTTON_DOWN        10
#define SNES_BUTTON_LEFT        9
#define SNES_BUTTON_RIGHT       8
#define SNES_BUTTON_A           7
#define SNES_BUTTON_X           6
#define SNES_BUTTON_L           5
#define SNES_BUTTON_R           4
#define SNES_BUTTON_NOT_USED_3  3
#define SNES_BUTTON_NOT_USED_2  2
#define SNES_BUTTON_NOT_USED_1  1
#define SNES_BUTTON_NOT_USED_0  0

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


class SNEStroller {
  public:
    SNEStroller();
    void begin(int pinClock, int pinLatch, int pinDataIn);
    void updateButtons();
    bool getButtonPressed(int button_requested);
    uint16_t getButtons();

  private:
    uint16_t _button_states;
    int _pin_clock;
    int _pin_latch;
    int _pin_data_in;
};

#endif
