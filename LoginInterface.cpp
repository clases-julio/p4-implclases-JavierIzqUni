/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "LoginInterface.h"
#include "CLLoginInterface.h"
#include "Database.h"
#include "User.h"
#include <iostream>
#include <vector>

LoginInterface::LoginInterface(){}

LoginInterface *LoginInterface::Create(const std::string type){
  if (type == "CLI"){
    return new CLLoginInterface;
  }
  else {
    throw std::runtime_error(type + " is not a defined LoginInterface type");
    std::exit(1);
  }
};

bool LoginInterface::checkUser(){
  this->user = this->dastabase.getUser(this->inputEmployeeNumber,this->inputNIF);
  return ! (user.isSameEmployeeNumber("00000") && user.isSameNIF("00000000")); // Is valid user 
}

User LoginInterface::getUser(){
  return this->user;
}

LoginInterface::~LoginInterface(){}