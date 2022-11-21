#include "Sensor.h"

#ifndef CAMERARGB_H 
#define	CAMERARGB_H 

class CameraRGB : public Sensor{
  public:
    CameraRGB(bool active = false, int valPerMin = 1);
    std::vector<int> requestData();
    ~CameraRGB();
  private:
    static int idNumber ;
};

#endif