#include "miasto.h"

Miasto::Miasto(std::string _nazwaMiasta)
  : liczbaMieszkancow(0), procent(0), nazwaMiasta(_nazwaMiasta), zadowolenieMiasta(0){
  }

// Konstruktor miasta, przypisanie atrybutow, oraz wstepne zaludnienie (wypelnienie mieszkancami) miasta
Miasto::Miasto(int _N, int _p, std::string _nazwaMiasta)
  : liczbaMieszkancow(_N), procent(_p), nazwaMiasta(_nazwaMiasta), zadowolenieMiasta(0){
  zaludnijMiasto();
}
// losuje pozycje kibicow i dzieli ich na dwie grupy:
// czerwonych i zielonych
void Miasto::zaludnijMiasto(){
  int liczbaCzerwonych = this->procent/100 * this->liczbaMieszkancow;
  int liczbaZielonych = this->liczbaMieszkancow - liczbaCzerwonych;

  for(int i = 0; i < liczbaCzerwonych; i++)
      this->kibice.push_back(Kibic('c'));

  for(int k = 0; k < liczbaZielonych; k++)
    this->kibice.push_back(Kibic('z'));
}

// Zwraca pozycje poszczegolnych kibicow
void Miasto::getPozycjeKibicow(){
  for(unsigned int i = 0; i < this->kibice.size(); i++)
    std::cout << kibice[i].getX() << "\t" << kibice[i].getY() << "\t" << kibice[i].getKolor() << std::endl;
}

// Sprawdza, czy kibice znajdują się odpowiednio blisko siebie, a także
// decyduje czy w związku z tym jego zadowolenie maleje, rośnie,
// czy nie zmienia się 
void Miasto::wyznaczZadowKibica(Kibic& k1, Kibic& k2){
  double k1Cord[] = {k1.getX(), k1.getY()};

  double k2Cord[] = {k2.getX(), k2.getY()};
  // Wyznaczenie odlgelosci pomiedzy  kibicami
  double dystans = pow(k2Cord[0] - k1Cord[0], 2) - pow(k2Cord[1] - k1Cord[1], 2);
  // Sprawdzanie odleglosci pomiedzy kibicami i decyzja o zwiekszeniu/zmniejszeniu poziomu zadowolenia
  if(dystans <= 1 && k1.getKolor() == k2.getKolor()){
    k1.zwiekszZadowolenie();
    k2.zwiekszZadowolenie();
  }
  
  else if (dystans <= 1 && k1.getKolor() != k2.getKolor()){
    k1.zmniejszZadowolenie();
    k2.zmniejszZadowolenie();
  }
}

// Przebiega po wszystkich parach kibicow wyznaczajac zadowolenie kazdego z nich
void Miasto::wyznaczCalkZadowKibicow(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    for(int j = i+1; j < this->liczbaMieszkancow; j++){
        this->wyznaczZadowKibica(this->kibice[i], this->kibice[j]);
    }
  }
}

// Sumuje poziomy zadowolenia kibicow, a kolejno wyznacza srednia arytmetyczna
// jako wskaznik ogolnego zadowolenia miasta
void Miasto::wyznaczZadowMiasta(){
  
  if(this->zadowolenieMiasta != 0)
    this->zadowolenieMiasta = 0;

  for(int i = 0; i < this->liczbaMieszkancow; i++){
    this->zadowolenieMiasta += kibice[i].getZadowolenie();
  }
  this->zadowolenieMiasta = this->zadowolenieMiasta / this->liczbaMieszkancow;
}

// Zwraca zadowolenie miasta
int Miasto::getZadowolenieMiasta(){
  return this->zadowolenieMiasta;
}

// Przeprowadza ewolucje miasta
void Miasto::ewolucja(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    // Sprawdza, czy zadowolenie kibica jest co najwyzej 0.
    // W takim przypadku losuje kat wzgledem OX. Na jego bazie w odpowiednim
    // kierunku zostaje przesunieta pozycja kibica (promien przesuniecia - 1)
    if(this->kibice[i].getZadowolenie() <= 0){
      double kierunek = 2 * rand()/RAND_MAX * M_PI;
      this->kibice[i].zmienX(cos(kierunek));
      this->kibice[i].zmienY(sin(kierunek));
    }
    else
      continue;
  }
}

// Przywraca zadowolenie kibicow do wartosci domyslnej - 0
void Miasto::resetZadowKibicow(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    this->kibice[i].resetZadow();
  }
}
Miasto::~Miasto(){
}
