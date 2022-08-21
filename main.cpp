#include <iostream>
#include <iomanip>
#include "kibic.h"
#include "miasto.h"
#include "interface.h"

int main()
{
    int liczbaMieszkancow = 0, liczbaEwolucji = 0, procent = 0; 
    std::string nazwaMiasta = "";
    Interface symulator;
    
    symulator.ustalWartParametrow(&nazwaMiasta, &liczbaMieszkancow, &procent, &liczbaEwolucji);

    if(true){
      City M(liczbaMieszkancow,procent,nazwaMiasta);
      M.calcTotCitizensHapp();
      M.calcCityHapp();
      int zadow = M.getCityHapp();
      printf("Poziom zadowolenia: %d\n", zadow);

      if(liczbaEwolucji != 0){
        for(int i = 0; i < liczbaEwolucji; i++){
          printf("Ewolucja %d:\n", i+1);
          M.evolve();
          M.resetCitizenHapp();
          M.calcTotCitizensHapp();
          M.calcCityHapp();
          zadow = M.getCityHapp();
          printf("Poziom zadowolenia: %d\n", zadow);
        }
      }
    }
  else{
      printf("Nieprawidłowa decyzja!\n");
      std::exit(0);
    }

    return 0;
}
