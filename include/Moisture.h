#include "Sensor.h"

#ifndef MOISTURE_H 
#define	MOISTURE_H

class Moisture : public Sensor{
  public:
    Moisture(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~Moisture();
  private:
    static int idNumber ;
};

#endif