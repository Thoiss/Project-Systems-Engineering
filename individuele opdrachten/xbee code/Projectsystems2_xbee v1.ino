#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ButtonB buttonB;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);    // aangeven dat de serial1 begint met 9600
  

}

void loop() {  // put your main code here, to run repeatedly:
 
char input = Serial1.read();    //de serial1 vanuit de xbee uitlezen en in de variabele 'input' stoppen

if (input == 's') {     //'input' vergelijken met de letter s
Serial.write("start");  //'start' schrijven op de serial1 naar de xbee
Serial.println("");     //een lijn opschuiven
ledRed(1);              // de rode led aanzetten
  }


if (input == 't') {     //'input' vergelijken met de letter t
Serial.write("stop");   //'stop' schrijven op de serial1
Serial.println("");     //regel opschuiven
ledRed(0);              //de rode led uitzetten
}

if (buttonB.isPressed()) {   //wanneer knop B wordt ingedrukt "B" uitprinten op de seriële monitor
  Serial1.print("B");        //de letter B uitprinten op de serial1
  delay(300);                 //delay van 300ms tussen de prints
  }
}
