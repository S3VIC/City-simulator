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
      Miasto M(liczbaMieszkancow,procent,nazwaMiasta);
      M.wyznaczCalkZadowKibicow();
      M.wyznaczZadowMiasta();
      int zadow = M.getZadowolenieMiasta();
      printf("Poziom zadowolenia: %d\n", zadow);

      if(liczbaEwolucji != 0){
        for(int i = 0; i < liczbaEwolucji; i++){
          printf("Ewolucja %d:\n", i+1);
          M.ewolucja();
          M.resetZadowKibicow();
          M.wyznaczCalkZadowKibicow();
          M.wyznaczZadowMiasta();
          zadow = M.getZadowolenieMiasta();
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
