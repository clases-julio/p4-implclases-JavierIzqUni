#include <string>
#include <vector>
#include "LoginInterface.h"
#include "Dashboard.h"

#ifndef INTERFACE_H 
#define	INTERFACE_H 

class Interface{
public:
  static Interface *Create(const std::string type = "CLI");
  Interface(); /* basic constructor */
  virtual void login(int tries) = 0;
  void login(std::string userNumber, std::string nif);
  bool loadMenu();
  virtual ~Interface();

protected:
  LoginInterface * loginInterface;
  Dashboard * dashboard;
};

#endif