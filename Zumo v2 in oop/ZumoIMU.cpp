#include "ZumoIMU.h"

ZumoIMU::ZumoIMU() {}

void ZumoIMU::init() {
    Wire.begin(); // Nodig voor het gebruik van de library functions
    imu.init(); // Initialiseren van de imu sensor
}

void ZumoIMU::read() {
    imu.read(); // Uitlezen van de imu sensor
}

