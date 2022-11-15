#include "Sensor.h"
#include "Menu.h"

#include <vector>

#ifndef CLMENU_H
#define	CLMENU_H

class CLMenu : public Menu{
  public:
    CLMenu(); /* basic constructor */
    void show(std::vector <Sensor *> );
    void show(Sensor *sensor);

  protected:
    void clearMenu();
};

#endif