#include "Dashboard.h"

#ifndef CLDASHBOARD_H
#define	CLDASHBOARD_H

class CLDashboard : public Dashboard{
  public:
    CLDashboard(); /* basic constructor */
    void showMainMenu();
    void changeInterface(std::string = "");
  protected:
    void readCommand();
    void listSensor();
};

#endif