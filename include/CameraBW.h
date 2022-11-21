#include "Sensor.h"

#ifndef CAMERABW_H 
#define	CAMERABW_H 

class CameraBW : public Sensor{
  public:
    CameraBW(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~CameraBW();
  private:
    static int idNumber ;
};

#endif