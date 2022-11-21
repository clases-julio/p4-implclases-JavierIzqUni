#include "Sensor.h"

#ifndef AIRQUALITY_H 
#define	AIRQUALITY_H

class AirQuality : public Sensor{
  public:
    AirQuality(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~AirQuality();
  private:
    static int idNumber ;
};

#endif