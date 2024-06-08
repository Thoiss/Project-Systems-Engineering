#include <iostream>
#include "zumo32U4ProximitySensors.h"
#include <string>

using namespace std;

class frontProxSensor : public Zumo32U4ProximitySensors{
    public:
    void read();
    void initFrontSensor();
    uint8_t countsFrontWithLeftLeds();
    uint8_t countsFrontWithRightLeds();
    private:
    uint32_t leftValue;
    uint32_t rightValue;
};