/**
 * @file CameraBW.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CameraBW.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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