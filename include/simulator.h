#pragma once

#include "miasto.h"
#include "kibic.h"
#include "interface.h"

class Simulator{
  private:
    int evolutionsNum;
  
  public:
    Simulator();

    void start();
    void beginSimulation(City* _myCity, Interface* _myInterface);
    void proceedEvolution();
    void setCityParams(Interface *myInterface, City *myCity);

    // Setters
    void setEvolutionNum();


    virtual ~Simulator();
};