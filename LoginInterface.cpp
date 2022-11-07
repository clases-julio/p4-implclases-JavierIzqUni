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

LoginInterface *LoginInterface::Create(std::string type){
  if (type == "CLI"){
    return new CLLoginInterface;
  }
  else {
    return new CLLoginInterface;
  }
};

bool LoginInterface::checkUser(){
  this->user = this->dastabase.getUser(this->inputEmployeeNumber,this->inputNIF);
  return ! (user.isSameEmployeeNumber("00000") && user.isSameNIF("00000000"));
}

User LoginInterface::getUser(){
  return this->user;
}

LoginInterface::~LoginInterface(){}