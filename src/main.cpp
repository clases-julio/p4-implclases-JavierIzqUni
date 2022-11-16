#include "Interface.h"
#include <iostream>

int main(int argc,char* argv[]){
  Interface *interfaceCli;
  interfaceCli = Interface::Create();
  std::cout << argc;
  if ( argc - 1  == 0 ){
    bool isRunning = true;
    while (isRunning) {
      // Execute the program until exit is requested
      interfaceCli->login(0);
      isRunning = ! interfaceCli->loadMenu();
    }
  }
  else if (argc - 1 == 2){
    interfaceCli->login(argv[1],argv[2]);
    interfaceCli->loadMenu();
  }
  
}
