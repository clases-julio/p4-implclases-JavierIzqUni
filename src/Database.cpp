#include "Database.h"
#include "User.h"
#include "Database.h"

Database::Database(){
  User *user1 = new User("10000","1234567A","paco");
  User *user2 = new User("20000","1234527J", "juan");
  Admin *admin1 = new Admin("30000","1234567C", "ELBOSS");
  addUser(*user1);
  addUser(*user2);
  addUser(*admin1);
}

User Database::getUser(std::string employeeNumber, std::string NIF){
  
  for (User i: this->user){
    if (i.isSameEmployeeNumber(employeeNumber) && i.isSameNIF(NIF)){
      i.addTimestamp();
      return i;
    }
  }
  User *user = new User();
  return *user;
}

void Database::addUser(User newUser){
  user.push_back(newUser);
}

Database::~Database(){}