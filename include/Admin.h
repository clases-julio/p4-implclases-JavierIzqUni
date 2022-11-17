#include "User.h"

#ifndef ADMIN_H
#define	ADMIN_H

class Admin : public User{
  public:
    Admin(std::string number = "00000",std::string nif = "00000000",std::string name = "default");
    ~Admin();
};

#endif