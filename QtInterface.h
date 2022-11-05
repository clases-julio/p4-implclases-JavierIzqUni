#include "Interface.h"

#ifndef QTINTERFACE_H 
#define	QTINTERFACE_H 

class QtInterface : public Interface{
  public:
    QtInterface(); /* basic constructor */
    void login();
    void loadMenu();
};

#endif