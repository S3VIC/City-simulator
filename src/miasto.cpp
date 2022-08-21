#include "miasto.h"

City::City(std::string _cityName)
  : citizenNum(0), procent(0), cityName(_cityName), cityHappiness(0){
  }

// Konstruktor miasta, przypisanie atrybutow, oraz wstepne zaludnienie (wypelnienie mieszkancami) miasta
City::City(int _N, int _p, std::string _cityName)
  : citizenNum(_N), procent(_p), cityName(_cityName), cityHappiness(0){
  populateCity();
}
// losuje pozycje kibicow i dzieli ich na dwie grupy:
// czerwonych i zielonych
void City::populateCity(){
  int liczbaCzerwonych = this->procent/100 * this->citizenNum;
  int liczbaZielonych = this->citizenNum - liczbaCzerwonych;

  for(int i = 0; i < liczbaCzerwonych; i++)
      this->citizens.push_back(Kibic('c'));

  for(int k = 0; k < liczbaZielonych; k++)
    this->citizens.push_back(Kibic('z'));
}

// Zwraca pozycje poszczegolnych kibicow
void City::getCitizensPos(){
  for(unsigned int i = 0; i < this->citizens.size(); i++)
    std::cout << citizens[i].getX() << "\t" << citizens[i].getY() << "\t" << citizens[i].getKolor() << std::endl;
}

// Sprawdza, czy kibice znajdują się odpowiednio blisko siebie, a także
// decyduje czy w związku z tym jego zadowolenie maleje, rośnie,
// czy nie zmienia się 
void City::calcSinglCitizenHapp(Kibic& k1, Kibic& k2){
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
void City::calcTotCitizensHapp(){
  for(int i = 0; i < this->citizenNum; i++){
    for(int j = i+1; j < this->citizenNum; j++){
        this->calcSinglCitizenHapp(this->citizens[i], this->citizens[j]);
    }
  }
}

// Sumuje poziomy zadowolenia kibicow, a kolejno wyznacza srednia arytmetyczna
// jako wskaznik ogolnego zadowolenia miasta
void City::calcCityHapp(){
  
  if(this->cityHappiness != 0)
    this->cityHappiness = 0;

  for(int i = 0; i < this->citizenNum; i++){
    this->cityHappiness += citizens[i].getZadowolenie();
  }
  this->cityHappiness = this->cityHappiness / this->citizenNum;
}

// Zwraca zadowolenie miasta
int City::getCityHapp(){
  return this->cityHappiness;
}

// Przeprowadza ewolucje miasta
void City::evolve(){
  for(int i = 0; i < this->citizenNum; i++){
    // Sprawdza, czy zadowolenie kibica jest co najwyzej 0.
    // W takim przypadku losuje kat wzgledem OX. Na jego bazie w odpowiednim
    // kierunku zostaje przesunieta pozycja kibica (promien przesuniecia - 1)
    if(this->citizens[i].getZadowolenie() <= 0){
      double kierunek = 2 * rand()/RAND_MAX * M_PI;
      this->citizens[i].zmienX(cos(kierunek));
      this->citizens[i].zmienY(sin(kierunek));
    }
    else
      continue;
  }
}

// Przywraca zadowolenie kibicow do wartosci domyslnej - 0
void City::resetCitizenHapp(){
  for(int i = 0; i < this->citizenNum; i++){
    this->citizens[i].resetZadow();
  }
}
City::~City(){
}
