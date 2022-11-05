#include <iostream>

#ifndef USER_H
#define	USER_H

class User{
public:
  User(std::string = "00000",std::string = "00000000");
  ~User();
  bool isSameNIF(std::string);
  bool isSameEmployeeNumber(std::string);
  void addTimestamp(std::string);
  std::string getTimestamp();

protected:
  std::string NIF; /* 8 digits */
  std::string employeeNumber; /* 5 digits */
  std::string lastLogTime; /* Placeholder */

  void setNIF(std::string);
  void setEmployeeNumber(std::string);
};

#endif