/**
 * @file LoginInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of LoginInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Database.h"

#ifndef LOGININTERFACE_H
#define	LOGININTERFACE_H

class LoginInterface{
public:
  static LoginInterface *Create(const std::string = "CLI");
  LoginInterface(); /* basic constructor */
  virtual ~LoginInterface();
  virtual void showWelcomeMessage() = 0;
  virtual void askEmployeeNumber() = 0;
  virtual void askEmployeeNumber(const std::string & userNumber) = 0;
  virtual void askNIF() = 0;
  virtual void askNIF(const std::string & userNumber) = 0;
  bool checkUser();
  User getUser();

protected:
  std::string inputNIF; /* 8 digits */
  std::string inputEmployeeNumber; /* 5 digits */
  User user;
  Database dastabase;
};

#endif