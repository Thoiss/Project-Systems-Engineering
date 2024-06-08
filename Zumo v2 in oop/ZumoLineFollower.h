#ifndef ZUMO_LINE_FOLLOWER_H
#define ZUMO_LINE_FOLLOWER_H

#include <Wire.h>
#include <Zumo32U4.h>
#include "ZumoCalibrator.h"
#include "ZumoPIDController.h"

class ZumoLineFollower {
public:
    ZumoLineFollower();
    void setup();
    void loop();

private:
    Zumo32U4LineSensors lineSensors;
    Zumo32U4ButtonA buttonA;
    Zumo32U4Motors motors;
    Zumo32U4Buzzer buzzer;

    ZumoCalibrator calibrator;
    ZumoPIDController pidController;

    unsigned int sensorWaarde[5];
    int maxVermogen;

    void checkuitkomst();
    void drive();
};

#endif // ZUMO_LINE_FOLLOWER_H