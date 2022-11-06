#include "MenuBar.h"

#ifndef CLMENUBAR_H
#define	CLMENUBAR_H

class CLMenuBar : public MenuBar{
  public:
    CLMenuBar(); /* basic constructor */
    void show();
  private:
    std::vector<std::string> buttons;
    std::string bar;
};

#endif