#include <iostream>
#include <iomanip>
#include <cmath>
#include "kibic.h"
#include "miasto.h"
#include "interface.h"
#include "simulator.h"

int main()
{
    //int citizensNum = 0, evolutionNum = 0, procent = 0; 
    //std::string cityName = "";
    Simulator mySimulator;
    mySimulator.startSimulation();
    
    

    
    //simulator.setParameters(&cityName, &citizensNum, &procent, &evolutionNum);
    /*
    if(true){
      City M(citizensNum,procent,cityName);
      simulator.saveToFile(M);
      simulator.plotData();
      M.calcTotCitizensHapp();
      M.calcCityHapp();
      int happ = M.getCityHapp();
      printf("Happiness level: %d\n", happ);

      if(evolutionNum != 0){
        for(int i = 0; i < evolutionNum; i++){
          printf("Evolution #%d:\n", i+1);
          M.evolve();
          M.resetCitizenHapp();
          M.calcTotCitizensHapp();
          M.calcCityHapp();
          happ = M.getCityHapp();
          printf("Happiness level: %d\n", happ);
        }
      }
    }
  else{
      printf("Unrecognized decision!\n");
      std::exit(0);
    }
//    std::system("pwd");
*/    return 0;
}
