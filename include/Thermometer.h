/**
 * @file Thermometer.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Thermometer.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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