# NEStroller
A library to interface the classic NES controller


# Usage

Create a global object for your controller.

    NEStroller myController;

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

    myController.getButtonPressed(NES_BUTTON_UP)
    
The button constants are...

    #define NES_BUTTON_UP         3
    #define NES_BUTTON_DOWN       2
    #define NES_BUTTON_LEFT       1
    #define NES_BUTTON_RIGHT      0
    #define NES_BUTTON_SELECT     5
    #define NES_BUTTON_START      4
    #define NES_BUTTON_A          7
    #define NES_BUTTON_B          6

If you'd like the raw byte return by the shift register you can call the getButtons method.

    byte button_data = myController.getButtons();
