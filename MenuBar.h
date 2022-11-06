#include <string>
#include <vector>

#ifndef MENUBAR_H
#define	MENUBAR_H

class MenuBar{
  public:
    static MenuBar *Create(std::string = "CLI");
    MenuBar(); /* basic constructor */
    virtual ~MenuBar();
    virtual void show() = 0;

};

#endif