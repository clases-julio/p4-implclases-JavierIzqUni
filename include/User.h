#include <iostream>

#ifndef USER_H
#define	USER_H

class User{
public:
  User(std::string number = "00000",std::string nif = "00000000",std::string name = "default");
  ~User();
  bool isSameNIF(std::string);
  bool isSameEmployeeNumber(std::string);
  std::string getName();
  void addTimestamp();
  std::string getTimestamp();
  bool hasAdminPermission();

protected:
  std::string name;
  std::string NIF; /* 8 digits */
  std::string employeeNumber; /* 5 digits */
  std::string lastLogTime;
  bool adminPermission;

  void setNIF(std::string);
  void setEmployeeNumber(std::string);
};

#endif