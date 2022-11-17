#include "Admin.h"
#include "User.h"

Admin::Admin(std::string employeeNumber, std::string NIF, std::string name): User(employeeNumber, NIF, name){
  this->adminPermission = true;
}

Admin::~Admin(){}