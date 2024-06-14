#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ButtonB buttonB;
Zumo32U4Motors motor

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);    // aangeven dat de serial1 begint met 9600
  

}

void loop() {  // put your main code here, to run repeatedly:
 
char input = Serial1.read();    //de serial1 vanuit de xbee uitlezen en in de variabele 'input' stoppen

if (input == 'w') {     //'input' vergelijken met de letter w
motor.setLeftSpeed(250);
motor.setrightSpeed(250);             
  }

if (input == 's') {     //'input' vergelijken met de letter s
motor.setLeftSpeed(-250);
motor.setrightSpeed(-250);           
  }

if (input == 'd') {     //'input' vergelijken met de letter d
motor.setLeftSpeed(150);
motor.setrightSpeed(250);            
  }

if (input == 'a') {     //'input' vergelijken met de letter w
motor.setLeftSpeed(250);
motor.setrightSpeed(150);           
  }

if (buttonB.isPressed()) {   //wanneer knop B wordt ingedrukt "B" uitprinten op de seriële monitor
  Serial1.print("B");        //de letter B uitprinten op de serial1
  delay(300);                 //delay van 300ms tussen de prints
  }
}
