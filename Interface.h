#include <string>
#include <vector>
#include "LoginInterface.h"
#include "Dashboard.h"

#ifndef INTERFACE_H 
#define	INTERFACE_H 

class Interface{
public:
  static Interface *Create(std::string = "CLI");
  Interface(); /* basic constructor */
  virtual void login() = 0;
  virtual void loadMenu() = 0;
  virtual ~Interface();

protected:
  LoginInterface * loginInterface;
  Dashboard dashboard;
};

#endif