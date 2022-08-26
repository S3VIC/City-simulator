#pragma once

#include "miasto.h"
#include "kibic.h"
#include "interface.h"

class Simulator{
  private:
    int evolutionNum;
  
  public:
    Simulator();
    City initializeCity();
    void startSimulation();
    void proceedEvolution();
    void setCityParams(Interface *myInterface, City *myCity);

    // Setters
    void setEvolutionNum();


    virtual ~Simulator();
};