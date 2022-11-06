#include <string>
#include <vector>
#include "Sensor.h"
#include "MenuBar.h"

#ifndef DASHBOARD_H
#define	DASHBOARD_H

class Dashboard{
  public:
    static Dashboard *Create(std::string = "CLI");
    Dashboard(); /* basic constructor */
    virtual ~Dashboard();
    virtual void showMainMenu() = 0;
    virtual void changeInterface() = 0;
    void exit();

  protected:
    std::vector <Sensor> sensor;
    MenuBar * menuBar;
};

#endif