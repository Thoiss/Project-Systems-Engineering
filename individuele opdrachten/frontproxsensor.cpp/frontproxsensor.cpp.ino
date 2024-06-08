#include "frontproxsensor.h"

frontProxSensor::frontProxSensor(){
  unsigned int microsecond = 1000000;
}

void frontProxSensor::setup(){
  frontProxSensor.initFrontSensor();
}
void frontProxSensor::loop(){
  frontProxSensor.read();

  //hier worden twee variabelen aangemaakt
  //het aantal helderheidniveaus worden terug gegeven voor de linker led,
  //die de voorste proximity sensor heeft geactiveerd.
  uint32_t leftValue = frontProxSensor.countsFrontWithLeftLeds();
  
  //het aantal helderheidniveaus worden terug gegeven voor de rechter led,
  //die de voorste proximity sensor heeft geactiveerd.
  uint32_t rightValue = frontProxSensor.countsFrontWithRightLeds();

  //Omkeren van de waarden.
  leftValue = 5 - leftValue;
  rightValue = 5 - rightValue;

  //Print de waarden.
  cout << "Linkerwaarde: " << leftValue << endl;      
                                                   
  cout << "Rechterwaarde: " << rightValue << endl;    


  usleep(microsecond/2); //delay(500);
  
  //Als één van de waardes gelijk is aan "0", 
  //dan wordt er geprint "Stop met rijden".
  if (leftValue == 0 || rightValue == 0) {
    cout << "Stop met rijden" << endl;
    usleep(microsecond * 5); //pas de delay aan voor de project.
  }
}
