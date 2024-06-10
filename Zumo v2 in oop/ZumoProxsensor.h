#ifndef PROXSENSOR_H
#define PROXSENSOR_H

#include <Zumo32U4ProximitySensors.h>

class ZumoProxsensor {
public:
    ZumoProxsensor();
    void init();
    void read();
    bool detect();
    void actuatesensor();

private:
    Zumo32U4ProximitySensors proxSensors;
    int frontproxreading
};

#endif // PROXSENSOR_H
