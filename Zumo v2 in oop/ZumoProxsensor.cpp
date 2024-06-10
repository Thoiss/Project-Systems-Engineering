#include "ZumoProxsensor.h"

ZumoProxsensor::ZumoProxsensor() {}

void ZumoProxsensor::init() {
    proxSensors.initFrontsensor();
}

int ZumoProxsensor::read() {
    proxSensors.read();
    frontproxreading = proxSensors.countsFrontWithLeftLeds() + proxSensors.countsFrontWithRightLeds();
    return frontproxreading;
}

bool ZumoProxsensor::detect() {
    if (frontproxreading > 6) {
        return true;
    }
    else {
        return false;
    }
}

int ZumoProxsensor::actuatesensor() {
    if (detect() = false) {
        motor.setSpeeds(-50, 50);
        delay(250);
    }
    else {
        motor.setSpeeds(100, 100);
    }
}
