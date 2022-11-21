#include "Sensor.h"

#ifndef HUMIDITY_H 
#define	HUMIDITY_H

class Humidity : public Sensor{
  public:
    Humidity(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~Humidity();
  private:
    static int idNumber ;
};

#endif