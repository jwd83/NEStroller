/*
  NEStrollerTest - A simple test for...
  NEStroller
  A simple NES controller interface for the Arduino
  Jared De Blander
  https://github.com/jared0x90
*/

#include "NEStroller.h"

// define your pins below

#define PIN_DATA   3 // yellow 
#define PIN_LATCH  5 // blue
#define PIN_CLOCK  7 // white

/*

  Constants defined in NEStroller.h

  #define NES_BUTTON_UP         3
  #define NES_BUTTON_DOWN       2
  #define NES_BUTTON_LEFT       1
  #define NES_BUTTON_RIGHT      0
  #define NES_BUTTON_SELECT     5
  #define NES_BUTTON_START      4
  #define NES_BUTTON_A          7
  #define NES_BUTTON_B          6

*/

NEStroller myController;

void setup() {
  // put your setup code here, to run once:

  // Setup the NEStroller
  myController.begin(
    /* int pinClock */  PIN_CLOCK ,
    /* int pinLatch */  PIN_LATCH ,
    /* int pinDataIn */ PIN_DATA
  );

  // Turn on serial
  Serial.begin(115200);

  while(!Serial) ;
  
  Serial.println("NEStroller Tester");
}

void loop() {
  // put your main code here, to run repeatedly:
  myController.updateButtons();
  
  byte button_data = myController.getButtons();

  // 255 means no buttons were pressed (but we did get a response!)
  if (button_data != 255) {
    Serial.print("Buttons = ");
    
    if (myController.getButtonPressed(NES_BUTTON_UP))     Serial.print("UP, ");
    if (myController.getButtonPressed(NES_BUTTON_DOWN))   Serial.print("DOWN, ");
    if (myController.getButtonPressed(NES_BUTTON_LEFT))   Serial.print("LEFT, ");
    if (myController.getButtonPressed(NES_BUTTON_RIGHT))  Serial.print("RIGHT, ");
    if (myController.getButtonPressed(NES_BUTTON_B))      Serial.print("B, ");
    if (myController.getButtonPressed(NES_BUTTON_A))      Serial.print("A, ");
    if (myController.getButtonPressed(NES_BUTTON_SELECT)) Serial.print("Select, ");
    if (myController.getButtonPressed(NES_BUTTON_START))  Serial.print("Start, ");

    Serial.print("[");
    for (int i = 7; i >= 0; i--) {
      Serial.print(bitRead(button_data, i));
    }
    Serial.println("]");
  }
  delay(10);
}
