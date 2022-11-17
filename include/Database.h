#include "User.h"
#include "Admin.h"
#include <vector>
#include <iostream>

#ifndef DATABASE_H 
#define	DATABASE_H 

class Database{
  public:
    Database(); /* basic constructor */
    ~Database();
    void addUser(User);
    User getUser(std::string,std::string);
  private:
    std::vector<User> user;
};

#endif