#include "Sensor.h"

#ifndef THERMOMETER_H 
#define	THERMOMETER_H

class Thermometer : public Sensor{
  public:
    Thermometer(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~Thermometer();
  private:
    static int idNumber ;
};

#endif