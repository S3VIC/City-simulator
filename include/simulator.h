#pragma once

#include "miasto.h"
#include "interface.h"
#include <fstream>

class Simulator
{
  private:
    int evolutionsNum;
  
  public:
    Simulator();

    void start();
    void beginSimulation(City* _myCity, Interface* _myInterface);
    void proceedEvolution(City* _myCity, int &evolutionNumber);
    void setCityParams(Interface *myInterface, City *myCity);
    void saveToFile(City &myCity);
    void plotData();
    void simulateWithFullPlotting(City *myCity);
    void simulateWithPartialPlotting(City *myCity);
    void simulateWithoutPlotting(City *myCity);

    // Setters
    void setEvolutionNum();


    virtual ~Simulator();
};