/**
 * @file CameraRGB.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CameraRGB.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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