/**
 * @file AirQuality.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of AirQuality.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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