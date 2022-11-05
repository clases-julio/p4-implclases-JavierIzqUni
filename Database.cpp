#include "Database.h"
#include "User.h"

Database::Database(){
  User user1 ("10000","1234567A");
  User user2 ("20000","1234527J");
  User user3 ("30000","1234347C");
  addUser(user1);
  addUser(user2);
  addUser(user3);
}

User Database::getUser(std::string employeeNumber, std::string NIF){
  for (User i: this->user){
    if (i.isSameEmployeeNumber(employeeNumber) && i.isSameNIF(NIF)){
      return i;
    }
  }
  User user;
  return user;
}

void Database::addUser(User newUser){
  user.push_back(newUser);
}

Database::~Database(){}