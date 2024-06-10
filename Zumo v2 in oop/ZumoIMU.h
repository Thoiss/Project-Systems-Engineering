#ifndef ZUMO_IMU_H
#define ZUMO_IMU_H
#define _USE_MATH_DEFINES

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4IMU imu;

class ZumoIMU {
public:
    ZumoIMU();
    void init();
    void read();
    void printData();
    float getPitch();

    

private:
    vector<int16_t> a = {0, 0, 0}
    float ax;
    float ay;
    float az;
    float pitch;
};

#endif