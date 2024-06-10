#ifndef ZUMO_IMU_H
#define ZUMO_IMU_H

#include <Wire.h>
#include <Zumo32U4.h>

class ZumoIMU {
public:
    ZumoIMU();
    void init();
    void read();
    void printData();
    vector<int16_t> m = {0, 0, 0}

private:
};

#endif