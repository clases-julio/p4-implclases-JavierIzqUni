#include "Interface.h"

#ifndef QTINTERFACE_H 
#define	QTINTERFACE_H 

class QTInterface : public Interface{
  public:
    QTInterface(); /* basic constructor */
    void login(int tries);
};

#endif