#include <iostream>
#include <iomanip>
#include "kibic.h"
#include "miasto.h"


int main()
{
    int N = 0;
    double p = 0, R = 0, r = 0;
    std::string nazwaMiasta = "";
    char decyzja = ' ';

    std::cout << "Losowe (r) tworzenie miasta, czy wczytanie danych z pliku (d)? : ";
    std::cin >> decyzja;
    std::cout << "Nazwa miasta: ";
    std::cin >> nazwaMiasta;
    std::cout << "Liczba mieszkańców: ";
    std::cin >> N;
    std::cout << "Procent mieszkańców jaki stanowią kibice czerwoni: ";
    std::cin >> p;
//    std::cout << "Max odległość przemieszczenia mieszkańca: ";
//    std::cin >> R;
//    std::cout << "Max odległość sprawdzania: ";
//    std::cin >> r;
    if(decyzja == 'r')
    {
      Miasto M(N,p,nazwaMiasta);
      M.getPozycjeKibicow();
    }
/*    else if (decyzja == 'd')
    {

    }
*/
 else
    {
      std::cout << "Nieprawidłowa decyzja!" << std::endl;
      std::exit(0);
    }

    return 0;
}
