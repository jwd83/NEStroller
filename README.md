# NEStroller
A library to interface the classic NES & SNES controllers

# Installation

Download NEStroller as a .zip from GitHub. Add it to your Arduino IDE via

**Top Menu -> Sketch -> Include Library -> Add .ZIP Library**

# Usage

Create a global object for your controller.

    NEStroller myController; 
    
    OR
    
    SNEStroller myController; 

In your setup function declare your pin definitions

    // Setup the NEStroller
    myController.begin(
      /* int pinClock */  4, 
      /* int pinLatch */  5, 
      /* int pinDataIn */ 6
    );

In your loop simply make a call to the updateButtons method to get the controller state.

    myController.updateButtons();
    
Once updated simply make a call to getButtonPressed with one of the button constants to
see if it has been pressed.

    if (myController.getButtonPressed(NES_BUTTON_UP)) Serial.print("UP, ");
    
The button constants are...

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

    

If you'd like the raw byte (NES) / uint16_t (SNES) return by the shift register you can call the getButtons method.

    auto button_data = myController.getButtons();
