#include "Sensor.h"
#include "Interface.h"
#include <iostream>

int main(){
  Interface *interfaceCli;
  interfaceCli = Interface::Create();
  interfaceCli->login();
}