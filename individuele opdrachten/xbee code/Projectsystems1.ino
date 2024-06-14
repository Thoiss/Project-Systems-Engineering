#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4ButtonA buttonA;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:


 if (buttonA.isPressed()) {   //wanneer knop A wordt ingedrukt "A" uitprinten op de seriële monitor
  Serial.print("A");
  delay(300);                 //delay van 300ms tussen de prints
 }
 if (buttonB.isPressed()) {   //wanneer knop B wordt ingedrukt "B" uitprinten op de seriële monitor
  Serial.print("B");
  delay(300);                 //delay van 300ms tussen de prints
 }
  if (buttonC.isPressed()) {  //wanneer knop B wordt ingedrukt "B" uitprinten op de seriële monitor
  Serial.print("C");
  delay(300);                 //delay van 300ms tussen de prints
 }

}


