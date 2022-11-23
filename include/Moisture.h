/**
 * @file Moisture.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Moisture.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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