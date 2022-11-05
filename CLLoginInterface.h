#include "LoginInterface.h"

#ifndef CLLOGININTERFACE_H
#define	CLLOGININTERFACE_H

class CLLoginInterface : public LoginInterface{
  public:
    CLLoginInterface(); /* basic constructor */
    void showWelcomeMessage(int);
    void askEmployeeNumber();
    void askNIF();
  private:
    void setTerminalWidth(int);
    int terminalWidth;
};

#endif