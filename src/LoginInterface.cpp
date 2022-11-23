/**
 * @file LoginInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LoginInterface.h"
#include "CLLoginInterface.h"

LoginInterface::LoginInterface(){}

/**
 * @brief Create a new Login interface instance of the type specified
 * 
 * @param type Type of login interface
 * @return LoginInterface* New login interface instance
 */
LoginInterface *LoginInterface::Create(const std::string type){
  if (type == "CLI"){
    return new CLLoginInterface;
  }
  else {
    throw std::runtime_error(type + " is not a defined LoginInterface type");
    std::exit(1);
  }
};

/**
 * @brief Check if the user data corresponds to a real user and stores the user
 * 
 * @return true = The user exists
 * @return false = The user does not exists
 */
bool LoginInterface::checkUser(){
  this->user = this->dastabase.getUser(this->inputEmployeeNumber,this->inputNIF);
  return ! (user.isSameEmployeeNumber("00000") && user.isSameNIF("00000000")); // Is valid user 
}

/**
 * @brief Returns the user that has previously logged in
 * 
 * @return User 
 * @see checkUser()
 */
User LoginInterface::getUser(){
  return this->user;
}

LoginInterface::~LoginInterface(){}