/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Dashboard.h"
#include "CLDashboard.h"
#include <iostream>
#include <vector>

Dashboard::Dashboard(){}

Dashboard *Dashboard::Create(std::string type){
  if (type == "CLI"){
    return new CLDashboard();
  }
  else {
    return new CLDashboard();
  }
};

void Dashboard::setUser(User user){
  this->user = user;
}

void Dashboard::exit(){
  std::exit(0);
}

Dashboard::~Dashboard(){}