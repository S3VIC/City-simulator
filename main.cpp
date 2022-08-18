#include <iostream>
#include <iomanip>
#include "kibic.h"
#include "miasto.h"


int main()
{
    int liczbaMieszkancow = 0, liczbaEwolucji = 0;
    double procent = 0;
    std::string nazwaMiasta = "";
//    char decyzja = ' ';

    printf("Nazwa miasta: ");
    std::cin >> nazwaMiasta;
    printf("Liczba mieszkańców: ");
    scanf("%d", &liczbaMieszkancow);
    printf("Procent mieszkańców jaki stanowią kibice czerwoni: ");
    scanf("%lf", &procent);
    printf("Liczba ewolucji: ");
    scanf("%d", &liczbaEwolucji);

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
