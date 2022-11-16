#include "Interface.h"


#ifndef CLINTERFACE_H 
#define	CLINTERFACE_H 

class CLInterface : public Interface{
  public:
    CLInterface(); /* basic constructor */
    void login(int tries);
    void loadMenu();
};

#endif