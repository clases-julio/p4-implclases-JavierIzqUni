#include "LoginInterface.h"

#ifndef CLLOGININTERFACE_H
#define	CLLOGININTERFACE_H

class CLLoginInterface : public LoginInterface{
  public:
    CLLoginInterface(); /* basic constructor */
    void showWelcomeMessage();
    void askEmployeeNumber();
    void askNIF();
};

#endif