#include "Database.h"
#include "User.h"

#include <iostream>

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