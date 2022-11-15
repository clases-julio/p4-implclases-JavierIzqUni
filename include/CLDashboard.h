#include "Dashboard.h"


#ifndef CLDASHBOARD_H
#define	CLDASHBOARD_H

class CLDashboard : public Dashboard{
  public:
    CLDashboard(); /* basic constructor */
    void showMainMenu();
    ~CLDashboard();
  protected:
    void changeMainMenu(int n);
    void readCommand();
    void listSensor();
    void helpCommand(std::string = "");
    void errorCommand(std::string = "");
};

#endif