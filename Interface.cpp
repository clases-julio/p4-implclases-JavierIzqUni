/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Interface.h"
#include "CLInterface.h"
#include "QtInterface.h"

Interface::Interface(){};

Interface *Interface::Create(std::string type){
  if (type == "CLI"){
    return new CLInterface;
  }
  else {
    return new QtInterface;
  }
};

Interface::~Interface(){};