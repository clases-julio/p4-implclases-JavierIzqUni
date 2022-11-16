#include <iostream>

#ifndef USER_H
#define	USER_H

class User{
public:
  User(std::string = "00000",std::string = "00000000",std::string = "default");
  ~User();
  bool isSameNIF(std::string);
  bool isSameEmployeeNumber(std::string);
  std::string getName();
  void addTimestamp();
  std::string getTimestamp();

protected:
  std::string name;
  std::string NIF; /* 8 digits */
  std::string employeeNumber; /* 5 digits */
  std::string lastLogTime; /* Placeholder */

  void setNIF(std::string);
  void setEmployeeNumber(std::string);
};

#endif