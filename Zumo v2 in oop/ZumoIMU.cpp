#include "ZumoIMU.h"
#include <cmath>

ZumoIMU::ZumoIMU() {
    float ax = imu.a.x;
    float ay = imu.a.y;
    float az = imu.a.z;
}

void ZumoIMU::init() {
    Wire.begin(); // Nodig voor het gebruik van de library functions
    imu.init(); // Initialiseren van de imu sensor
}

void ZumoIMU::read() {
    imu.read(); // Uitlezen van de imu sensor
}

void ZumoIMU::printData(){
    Serial.println(pitch); // Print de data van de pitch voor het testen
}

float ZumoIMU::getPitch() {
    // float pitch = atan2(ax / sqrt(ay * ay + az * az)) * (180 / PI);
    float pitch = atan2(ax / ay) * (180 / M_PI); // Bron voor de berekening van de pitch: https://atadiat.com/en/e-towards-understanding-imu-basics-of-accelerometer-and-gyroscope-sensors/

}