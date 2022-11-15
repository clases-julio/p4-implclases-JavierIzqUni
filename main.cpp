#include "Interface.h"
#include <iostream>
#include <unistd.h>

int main(){
  Interface *interfaceCli;
  interfaceCli = Interface::Create();
  bool isRunning = true;
  while (isRunning) {
    // Execute the program until exit is requested
    interfaceCli->login(0);
    isRunning = ! interfaceCli->loadMenu();
  }
}