#include "ZumoLineFollower.h"

ZumoLineFollower::ZumoLineFollower() : 
    calibrator(lineSensors, buttonA, buzzer),
    pidController(maxVermogen, 2000, 1.5, 1.5, 0.5), // maxvermogen, target error, const_int, const_afg, const_error
    maxVermogen(400) {}

void ZumoLineFollower::setup() {
    buttonA.waitForButton();
    lineSensors.initFiveSensors();
    calibrator.calibrateColor();
    calibrator.calibrateLineSensors(motors);
    delay(1000);
    buttonA.waitForButton();
    delay(200);
}

void ZumoLineFollower::checkuitkomst() {
    Serial.print(sensorWaarde[1]);
    Serial.print(" ");
    Serial.print(sensorWaarde[2]);
    Serial.print(" ");
    Serial.print(sensorWaarde[3]);
    Serial.println();
}

void ZumoLineFollower::drive() {
    int green = calibrator.getColorValue("green");
    int brown = calibrator.getColorValue("brown");
    int black = calibrator.getColorValue("black");
    int gray = calibrator.getColorValue("gray");

    if (sensorWaarde[2] > green - 20 && sensorWaarde[2] < green + 20) {
        maxVermogen = 200;
    } else if (sensorWaarde[2] > brown - 20 && sensorWaarde[2] < brown + 20) {
        motors.setSpeeds(0, 0);
        buzzer.play(">g32");
        motors.setSpeeds(100, 100);
        delay(1000);
    } else if (sensorWaarde[2] > black - 20 && sensorWaarde[2] < black + 20) {
        maxVermogen = 350;
    } else if (sensorWaarde[2] > gray - 20 && sensorWaarde[2] < gray + 20) {
        // implementatie van het afslaan naar links of rechts bij grijs detectie
    }
    // else {
    // Implementatie van sumo deel met blokje uit de cirkel beuken
    // }

}

void ZumoLineFollower::loop() {
    lineSensors.read(sensorWaarde);
    drive();
    int error = lineSensors.readLine(sensorWaarde);
    pidController.excecute(error, motors);
}