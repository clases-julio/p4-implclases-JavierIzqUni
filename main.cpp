#include "Sensor.h"
#include "Interface.h"
#include <iostream>
#include <unistd.h>

int main(){
  Interface *interfaceCli;
  interfaceCli = Interface::Create();
  interfaceCli->login();
  usleep(1 * 1000000);
  interfaceCli->loadMenu();
}