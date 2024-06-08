#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;

// Here I can set the continuous speed for the motors
const uint16_t motorSpeed = 300;

void setup() {
  // Wait for user to press button A to start program.
  buttonA.waitForButton();

  // Wait for user to press button B to start program.
  buttonB.waitForButton();

  // Wait for user to press button C to start program.
  buttonC.waitForButton();  
}

void loop() {
  // Check if button A has been pressed
  bool buttonPressA = buttonA.getSingleDebouncedPress();
  bool buttonPressB = buttonB.getSingleDebouncedPress();
  bool buttonPressC = buttonC.getSingleDebouncedPress();

  if (buttonPressA) {
    // Time to remove finger from button
    delay(1000);

    // Run both motors in forward direction for 3 seconds
    motors.setSpeeds(motorSpeed, motorSpeed);
    delay(3000);

    // Stop both motors (takes half a second)
    motors.setSpeeds(0,0);
    delay(500);
  }

  if (buttonPressB) {
    // Time to remove finger from button
    delay(1000);

    // Run both motors in backwards direction for 3 seconds
    motors.setSpeeds(-motorSpeed, -motorSpeed);
    delay(3000);

    // Stop both motors (takes half a second)
    motors.setSpeeds(0,0);
    delay(500);
  }

  if (buttonPressC) {
    // Turn in a circle for 5 seconds
    motors.setSpeeds(motorSpeed, -motorSpeed);
    delay(500);
    
    // Stop both motors (takes half a second)
    motors.setSpeeds(0,0);
    delay(500);
  }
}